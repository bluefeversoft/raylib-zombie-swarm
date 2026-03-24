#include <algorithm>
#include "raylib.h"


constexpr int BASE_W = 1280;
constexpr int BASE_H = 720;


int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(BASE_W, BASE_H, "Swarm");
    SetTargetFPS(60);

    ChangeDirectory(TextFormat("%s/../assets/images", GetApplicationDirectory()));

    Texture2D background = LoadTexture("Floor.png");
    Texture2D walls       = LoadTexture("Walls.png");

    RenderTexture2D canvas = LoadRenderTexture(BASE_W, BASE_H);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_BILINEAR);

    while (!WindowShouldClose())
    {
        BeginTextureMode(canvas);
            DrawTexture(background, 0, 0, WHITE);
            DrawTexture(walls, 0, 0, WHITE);
            DrawText("It works!", 24, 24, 20, WHITE);
        EndTextureMode();

        float scale = std::min(
            (float)GetScreenWidth() / BASE_W,
            (float)GetScreenHeight() / BASE_H
        );

        float offsetX = (GetScreenWidth() - BASE_W * scale) * 0.5f;
        float offsetY = (GetScreenHeight() - BASE_H * scale) * 0.5f;
        
        Rectangle src  = { 0, 0, (float)BASE_W, -(float)BASE_H };
        Rectangle dest = { offsetX, offsetY, BASE_W * scale, BASE_H * scale };
        
        BeginDrawing();
            ClearBackground(BLACK);          
            DrawTexturePro(canvas.texture, src, dest, {0, 0}, 0.0f, WHITE);
        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(walls);
    UnloadRenderTexture(canvas);
    CloseWindow();
    return 0;
}