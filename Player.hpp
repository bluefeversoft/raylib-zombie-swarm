#pragma once

#include "raylib.h"
#include "Transform2D.hpp"
#include "Sprite.hpp"
#include "Movement.hpp"
#include "CollisionMap.hpp"


class Player
{
public:
    Player(Texture2D* tex);

    void Draw() const;
    void Update(Vector2 moveDir, float delta);
    void SetCollisionMap(const CollisionMap* map);

    Vector2 GetPosition() const;
    void SetPosition(Vector2 position);

private:
    Transform2D _transform;
    Sprite _sprite;
    Movement _movement;
    const CollisionMap* _collisionMap = nullptr;
};
