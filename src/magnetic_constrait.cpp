#include "magnetic_constrait.h"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/object.hpp"
#include "godot_cpp/classes/rigid_body3d.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/defs.hpp"
#include "godot_cpp/variant/node_path.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector3.hpp"

using namespace godot;

void MagneticConstraint::_bind_methods() {
  ClassDB::bind_method(D_METHOD("set_body1_path", "path"),
                       &MagneticConstraint::set_body1_path);
  ClassDB::bind_method(D_METHOD("get_body1_path"),
                       &MagneticConstraint::get_body1_path);
  ClassDB::bind_method(D_METHOD("set_body2_path", "path"),
                       &MagneticConstraint::set_body2_path);
  ClassDB::bind_method(D_METHOD("get_body2_path"),
                       &MagneticConstraint::get_body2_path);

  ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "body1_path"), "set_body1_path",
               "get_body1_path");
  ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "body2_path"), "set_body2_path",
               "get_body2_path");
}

void MagneticConstraint::_ready() {
  if (Engine::get_singleton()->is_editor_hint()) {
    return;
  }

  body1 = get_node<RigidBody3D>(body1_path);
  body2 = get_node<RigidBody3D>(body2_path);
}

void MagneticConstraint::_physics_process(double delta) {
  if (Engine::get_singleton()->is_editor_hint() || !body1 || !body2) {
    return;
  }

  Vector3 pos1 = body1->get_global_position();
  Vector3 pos2 = body2->get_global_position();
  Vector3 delta_pos = pos2 - pos1;
  real_t distance_sq = delta_pos.length_squared();

  if (distance_sq < 0.0001) {
    return;
  }

  Variant strength1_var = body1->get("magnetic_strength");
  Variant strength2_var = body2->get("magnetic_strength");
  Variant pole1_var = body1->get("magnetic_pole");
  Variant pole2_var = body2->get("magnetic_pole");

  if (strength1_var.get_type() != Variant::FLOAT ||
      strength2_var.get_type() != Variant::FLOAT) {
    return;
  }

  real_t strength1 = strength1_var;
  real_t strength2 = strength2_var;
  real_t pole1 = pole1_var;
  real_t pole2 = pole2_var;

  real_t product = pole1 * pole2;
  Vector3 direction = delta_pos.normalized();
  real_t force_magnitude = (strength1 * strength2) / distance_sq;

  Vector3 force = direction * product * force_magnitude;

  body1->apply_central_force(force);
  body2->apply_central_force(-force);
}

void MagneticConstraint::set_body1_path(const NodePath &p_path) {
  body1_path = p_path;
}
NodePath MagneticConstraint::get_body1_path() const { return body1_path; }

void MagneticConstraint::set_body2_path(const NodePath &p_path) {
  body2_path = p_path;
}
NodePath MagneticConstraint::get_body2_path() const { return body2_path; }
