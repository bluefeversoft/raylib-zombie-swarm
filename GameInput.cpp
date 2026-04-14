#include "GameInput.hpp"
#include "GameConfig.hpp"
#include "raymath.h"

void GameInput::Update()
{   
    _state.moveDir.x = (IsKeyDown(KEY_D) ? 1.0f : 0.0f) - (IsKeyDown(KEY_A) ? 1.0f : 0.0f);
    _state.moveDir.y = (IsKeyDown(KEY_S) ? 1.0f : 0.0f) - (IsKeyDown(KEY_W) ? 1.0f : 0.0f);

    if(Vector2Length(_state.moveDir) > 0)
        _state.moveDir = Vector2Normalize(_state.moveDir);

    _state.aimAngle += GetMouseDelta().x * 
                    (GameConfig::BASE_W / (float)GetScreenWidth()) * 
                    GameConfig::AIM_SENSITIVITY;
}