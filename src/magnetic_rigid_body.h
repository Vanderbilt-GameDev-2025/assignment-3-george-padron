#ifndef MAGNETIC_RIGIDBODY_H
#define MAGNETIC_RIGIDBODY_H

#include "godot_cpp/classes/rigid_body3d.hpp"
#include "godot_cpp/classes/wrapped.hpp"
namespace godot {
class MagneticRigidBody3D : public RigidBody3D {
  GDCLASS(MagneticRigidBody3D, RigidBody3D)

private:
  float magnetic_strength = 100.0;
  float magnetic_pole = 1.0;

public:
  MagneticRigidBody3D();
  void set_magnetic_strength(float p_strength);
  float get_magnetic_strength() const;

  void set_magnetic_pole(float p_pole);
  float get_magnetic_pole() const;

  static void _bind_methods();
};

} // namespace godot

#endif //  MAGNETIC_RIGIDBODY_H
