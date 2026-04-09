#pragma once
#include "raylib.h"
#include "Transform2D.hpp"


class CollisionMap;


struct Movement
{
    float speed = 0.0f;

    void Update(Transform2D& transform, Vector2 moveDir,
         float delta, const CollisionMap* collisionMap = nullptr);
};
