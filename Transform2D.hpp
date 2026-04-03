#pragma once
#include "raylib.h"


struct Transform2D
{
    Vector2 position = { 0, 0 };
    float rotation = 0.0f;
    float scale = 1.0f;    
};
