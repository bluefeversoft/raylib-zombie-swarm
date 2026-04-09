#include "CollisionMap.hpp"
#include "GameConfig.hpp"


void CollisionMap::Init(const Image* img)
{
    _img = img;
}

bool CollisionMap::IsWalkable(float x, float y) const
{
    if (!_img || !_img->data) return false;

    int px = (int)x;
    int py = (int)y;

    if(px < 0 || px >= _img->width || py < 0 || py >= _img->height)
        return false;
    
    Color pixel = GetImageColor(*_img, px, py);
    return pixel.r > GameConfig::WALKABLE_THRESHOLD;
}


