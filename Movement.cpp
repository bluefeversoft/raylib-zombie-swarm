#include "Movement.hpp"


void Movement::Update(Transform2D& transform, Vector2 moveDir, float delta)
{
    transform.position.x += moveDir.x * speed * delta;
    transform.position.y += moveDir.y * speed * delta;
}
