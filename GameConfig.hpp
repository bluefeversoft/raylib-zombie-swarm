#pragma once
#include "raylib.h"


namespace GameConfig {
    constexpr int BASE_W = 1280;
    constexpr int BASE_H = 720;

    // Player
    constexpr float PLAYER_SCALE = 0.3f;
    constexpr float PLAYER_SPEED = 200.0f;
    constexpr float AIM_SENSITIVITY = 0.15f;
    constexpr Vector2 PLAYER_PIVOT = { 0.31f, 0.58f };

    // Collision
    constexpr unsigned char WALKABLE_THRESHOLD = 240;
}
