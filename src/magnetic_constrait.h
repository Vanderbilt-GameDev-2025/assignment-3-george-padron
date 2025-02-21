#ifndef MAGNETIC_CONSTRAINT_H
#define MAGNETIC_CONSTRAINT_H

#include "godot_cpp/variant/node_path.hpp"
#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/rigid_body3d.hpp"

namespace godot {

class MagneticConstraint : public Node3D {
  GDCLASS(MagneticConstraint, Node3D)

private:
  NodePath body1_path;
  NodePath body2_path;
  RigidBody3D *body1 = nullptr;
  RigidBody3D *body2 = nullptr;

protected:
  static void _bind_methods();

public:
  void _ready() override;
  void _physics_process(double delta) override;

  void set_body1_path(const NodePath &p_path);
  NodePath get_body1_path() const;

  void set_body2_path(const NodePath &p_path);
  NodePath get_body2_path() const;
};
 
} // namespace godot

#endif // MAGNETIC_CONSTRAINT_H
