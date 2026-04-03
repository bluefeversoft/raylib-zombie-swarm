#pragma once
#include "raylib.h"
#include "Transform2D.hpp"


struct Sprite
{
    static bool showDebug;
    
    const Texture2D* texture = nullptr;
    Vector2 pivot = { 0.5f, 0.5f };

    void Init(Texture2D* tex);
    void Draw(const Transform2D& transform) const;
};
