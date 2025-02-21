#ifndef MAGNETIC_CONSTRAINT_H
#define MAGNETIC_CONSTRAINT_H

#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/rigid_body3d.hpp"
#include "godot_cpp/templates/vector.hpp"
#include "magnetic_rigid_body.h"

#define MAGNETIC_BODIES_GROUP "magnetic_bodies"

namespace godot {

class MagneticConstraint : public Node3D {
  GDCLASS(MagneticConstraint, Node3D)

private:
  float global_force_scale = 1.0;
  Vector<MagneticRigidBody3D*> magnetic_bodies;

protected:
  static void _bind_methods();

public:
  void _ready() override;
  void _physics_process(double delta) override;

  void set_global_force_scale(float p_scale);
  float get_global_force_scale() const;
};

} // namespace godot

#endif // MAGNETIC_CONSTRAINT_H
