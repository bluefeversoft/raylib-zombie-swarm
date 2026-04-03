#pragma once

#include "raylib.h"
#include "Transform2D.hpp"
#include "Sprite.hpp"
#include "Movement.hpp"


class Player
{
public:
    Player(Texture2D* tex);

    void Draw() const;
    void Update(Vector2 moveDir, float delta);

    Vector2 GetPosition() const;
    void SetPosition(Vector2 position);

private:
    Transform2D _transform;
    Sprite _sprite;
    Movement _movement;
};
