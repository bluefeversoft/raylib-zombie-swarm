#include "Sprite.hpp"


bool Sprite::showDebug = false;


void Sprite::Init(Texture2D* tex)
{
    texture = tex;
}

void Sprite::Draw(const Transform2D& transform) const
{
    if(!texture) return;

    float w = texture->width * transform.scale;
    float h = texture->height * transform.scale;

    Vector2 drawPos = {
        transform.position.x - w * pivot.x,
        transform.position.y - h * pivot.y
    };

    DrawTextureEx(*texture, drawPos, transform.rotation, transform.scale, WHITE);

    if(showDebug)
        DrawCircle((int)transform.position.x, (int)transform.position.y, 2.0f, RED);
}
