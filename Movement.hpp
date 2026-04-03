#pragma once
#include "raylib.h"
#include "Transform2D.hpp"

struct Movement
{
    float speed = 0.0f;

    void Update(Transform2D& transform, Vector2 moveDir, float delta);
};
