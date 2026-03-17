# Raylib Setup - macOS

## 1. Install Homebrew and Xcode Tools

Install Homebrew from [https://brew.sh/](https://brew.sh/). This will also install the Xcode command-line tools.

When the installation finishes, it will tell you to run three commands — **make sure to run those!**

## 2. Install Raylib

```bash
brew install raylib
```

## 3. Create Your Project

Make a folder for your project and open it in VS Code.

Create three folders:

```
.vscode/
build/
src/
```

## 4. Configure VS Code

In `.vscode/` create three files with the following content.

### `c_cpp_properties.json`

> **Note:** On Intel Macs the include path is `/usr/local/include`, **not** `/opt/homebrew/include`.

```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**",
                "/opt/homebrew/include"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "clang-x64"
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
            "command": "g++",
            "args": [
                "${workspaceFolder}/src/*.cpp",
                "-o",
                "${workspaceFolder}/build/main",
                "-std=c++17",
                "-lraylib",
                "-framework", "OpenGL",
                "-framework", "Cocoa",
                "-framework", "IOKit",
                "-framework", "CoreAudio",
                "-framework", "CoreVideo"
            ],
            "group": { "kind": "build", "isDefault": true },
            "problemMatcher": "$gcc"
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
            "type": "lldb",
            "request": "launch",
            "program": "${workspaceFolder}/build/main",
            "args": [],
            "cwd": "${workspaceFolder}"
        }
    ]
}
```

## 5. Add Starter Code

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

## 6. Build and Run

Press `Ctrl+Shift+B` to build, then `F5` to debug.
