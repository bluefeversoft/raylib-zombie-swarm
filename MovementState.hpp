#pragma once
#include <raylib.h>


struct MovementState
{
    Vector2 moveDir = { 0.0f, 0.0f };
    float aimAngle = 0.0f;
};
