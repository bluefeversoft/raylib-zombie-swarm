#include "Movement.hpp"
#include "CollisionMap.hpp"

void Movement::Update(Transform2D& transform, const MovementState& movementState, float delta,
                    const CollisionMap *collisionMap)
{
    float newX = transform.position.x + movementState.moveDir.x * speed * delta;
    float newY = transform.position.y + movementState.moveDir.y * speed * delta;

    transform.rotation = movementState.aimAngle;

    if(collisionMap)
    {
        if(collisionMap->IsWalkable(newX, transform.position.y))
            transform.position.x = newX;
        if(collisionMap->IsWalkable(transform.position.x, newY))
            transform.position.y = newY;
    }
    else
    {
        transform.position.x = newX;
        transform.position.y = newY;
    }
}
