# Raylib Setup - Linux

## 1. Install Dependencies

### Ubuntu / Debian

```bash
sudo apt update
sudo apt install build-essential git libraylib-dev
```

If `libraylib-dev` is not available or too old in your distro's repos, install raylib from source instead:

```bash
sudo apt install build-essential git libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev

git clone --depth 1 https://github.com/raysan5/raylib.git /tmp/raylib
cd /tmp/raylib/src
make PLATFORM=PLATFORM_DESKTOP
sudo make install
```

### Fedora

```bash
sudo dnf install gcc gcc-c++ make raylib-devel
```

Or from source:

```bash
sudo dnf install gcc gcc-c++ make alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel libatomic wayland-devel libxkbcommon-devel

git clone --depth 1 https://github.com/raysan5/raylib.git /tmp/raylib
cd /tmp/raylib/src
make PLATFORM=PLATFORM_DESKTOP
sudo make install
```

### Arch Linux

```bash
sudo pacman -S base-devel raylib
```

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

### `c_cpp_properties.json`

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/local/include"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64"
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
                "-lGL",
                "-lm",
                "-lpthread",
                "-ldl",
                "-lrt",
                "-lX11"
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
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/main",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
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
