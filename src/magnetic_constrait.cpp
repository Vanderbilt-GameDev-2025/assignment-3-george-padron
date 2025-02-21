#include "magnetic_constrait.h"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/defs.hpp"
#include "godot_cpp/variant/array.hpp"
#include "godot_cpp/variant/node_path.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector3.hpp"
#include "magnetic_rigid_body.h"

using namespace godot;

void MagneticConstraint::_bind_methods() {
  ClassDB::bind_method(D_METHOD("set_global_force_scale", "scale"),
                       &MagneticConstraint::set_global_force_scale);
  ClassDB::bind_method(D_METHOD("get_global_force_scale"),
                       &MagneticConstraint::get_global_force_scale);

  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "global_force_scale"),
               "set_global_force_scale", "get_global_force_scale");
}

void MagneticConstraint::_ready() {
  if (Engine::get_singleton()->is_editor_hint()) {
    return;
  }

  magnetic_bodies.clear();

  Array nodes = get_tree()->get_nodes_in_group(MAGNETIC_BODIES_GROUP);
  for (int i = 0; i < nodes.size(); ++i) {
    auto *body = Object::cast_to<MagneticRigidBody3D>(nodes[i]);
    if (body) {
      magnetic_bodies.append(body);
    }
  }
}

void MagneticConstraint::_physics_process(double delta) {
  if (Engine::get_singleton()->is_editor_hint()) {
    return;
  }
  for (int i = 0; i < magnetic_bodies.size(); ++i) {
    for (int j = i + 1; j < magnetic_bodies.size(); ++j) {
      MagneticRigidBody3D *a = magnetic_bodies[i];
      MagneticRigidBody3D *b = magnetic_bodies[j];

      if (!a || !b) {
        continue;
      }

      Vector3 pos_a = a->get_global_position();
      Vector3 pos_b = b->get_global_position();
      Vector3 delta_pos = pos_b - pos_a;
      real_t distance_sq = delta_pos.length_squared();

      // Prevent division by zero
      if (distance_sq < 0.0001) {
        continue;
      }

      real_t force_magnitude =
          (a->get_magnetic_strength() * b->get_magnetic_strength()) /
          distance_sq * global_force_scale;

      Vector3 force_dir = delta_pos.normalized();
      real_t pole_product = a->get_magnetic_pole() * b->get_magnetic_pole();

      // Apply equal and opposite forces
      a->apply_central_force(force_dir * force_magnitude * pole_product);
      b->apply_central_force(-force_dir * force_magnitude * pole_product);
    }
  }
}

void MagneticConstraint::set_global_force_scale(float p_scale) {
  global_force_scale = p_scale;
}
float MagneticConstraint::get_global_force_scale() const {
  return global_force_scale;
}
