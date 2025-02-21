#include "magnetic_rigid_body.h"
#include "godot_cpp/core/class_db.hpp"
#include "magnetic_constrait.h"

using namespace godot;

MagneticRigidBody3D::MagneticRigidBody3D() {
  this->add_to_group(MAGNETIC_BODIES_GROUP);
}

void MagneticRigidBody3D::_bind_methods() {
  ClassDB::bind_method(D_METHOD("set_magnetic_strength", "strength"),
                       &MagneticRigidBody3D::set_magnetic_strength);
  ClassDB::bind_method(D_METHOD("get_magnetic_strength"),
                       &MagneticRigidBody3D::get_magnetic_strength);
  ClassDB::bind_method(D_METHOD("set_magnetic_pole", "pole"),
                       &MagneticRigidBody3D::set_magnetic_pole);
  ClassDB::bind_method(D_METHOD("get_magnetic_pole"),
                       &MagneticRigidBody3D::get_magnetic_pole);

  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "magnetic_strength"),
               "set_magnetic_strength", "get_magnetic_strength");
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "magnetic_pole"),
               "set_magnetic_pole", "get_magnetic_pole");
}

void MagneticRigidBody3D::set_magnetic_strength(float p_strength) {
  magnetic_strength = p_strength;
}
float MagneticRigidBody3D::get_magnetic_strength() const {
  return magnetic_strength;
}

void MagneticRigidBody3D::set_magnetic_pole(float p_pole) {
  magnetic_pole = CLAMP(p_pole, -1.0f, 1.0f);
}
float MagneticRigidBody3D::get_magnetic_pole() const { return magnetic_pole; }

// namespace godot
