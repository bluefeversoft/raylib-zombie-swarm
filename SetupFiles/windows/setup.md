# Raylib Setup - Windows

## 1. Install Raylib

Download and run the [raylib installer](https://github.com/raysan5/raylib/releases).

## 2. Create Your Project

Make a folder for your project and open it in VS Code.

Create three folders:

```
.vscode/
build/
src/
```

## 3. Configure VS Code

In `.vscode/` create three files with the following content.

> **Note:** This assumes you installed raylib at the default location (`C:/raylib`).

### `c_cpp_properties.json`

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/raylib/raylib/src"
            ],
            "defines": [],
            "compilerPath": "C:/raylib/w64devkit/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}
```

### `tasks.json`

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build",
            "type": "shell",
            "command": "C:/raylib/w64devkit/bin/g++.exe",
            "args": [
                "${workspaceFolder}/src/*.cpp",
                "-o",
                "${workspaceFolder}/build/main.exe",
                "-I",
                "C:/raylib/raylib/src",
                "-L",
                "C:/raylib/raylib/src",
                "-lraylib",
                "-lopengl32",
                "-lgdi32",
                "-lwinmm"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": "$gcc",
            "options": {
                "env": {
                    "PATH": "C:/raylib/w64devkit/bin;${env:PATH}"
                }
            }
        }
    ]
}
```

### `launch.json`

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/main.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/raylib/w64devkit/bin/gdb.exe",
            "preLaunchTask": "Build"
        }
    ]
}
```

## 4. Add Starter Code

In the `src/` folder, create `main.cpp`:

```cpp
#include "raylib.h"

int main()
{
    InitWindow(1280, 720, "Swarm");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("It works!", 24, 24, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
```

## 5. Build and Run

Press `Ctrl+Shift+B` to build, then `F5` to debug.
