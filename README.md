# 🐍 Retro Snake Game (Advanced Console Implementation)

A high-performance, responsive recreation of the classic **Snake Game** built in pure C. This project focuses on efficient console memory rendering, matrix-based collision detection, and custom map layouts using Windows API handles.

---

## 🚀 Key Technical Features (Resume Highlights)

* **Unicode & UTF-16 Rendering:** Avoided standard ASCII limitations by configuring `stdout` to `_O_U16TEXT` mode. This enables rendering high-resolution block characters (`█`, `●`, `■`) for a modern retro look without visual tearing.
* **Low-Latency Input Processing:** Utilizes non-blocking input handling via `_kbhit()` and `_getch()`, ensuring fluid player controls without interrupting the core execution loop.
* **Flicker-Free Console Graphics:** Replaced full-screen refreshes (`system("cls")`) with a precise coordinate-updating algorithm via `SetConsoleCursorPosition` (Windows API), significantly optimizing rendering speed and eliminating screen flickering.
* **Dynamic Collision & Map Matrices:** Implemented an underlying 2D array representation (`map[HEIGHT][WIDTH]`) for seamless real-time tracking of game entities (walls, snake body, and food spawns).

---

## 🛠️ Architecture & Core Mechanics

### 1. Game State Representation
The grid tracks multiple entity states using integer definitions:
* `0`: Empty space
* `1`: Wall obstacles / Map borders
* `2`: Snake segments
* `3`: Food items (Apples)

### 2. Snake Mechanics
The snake’s position is managed through coordinate tracking arrays (`snakeX[]`, `snakeY[]`). When food is consumed, the system dynamically scales the `snakeLength` buffer and triggers random food placement validated against the current obstacle grid to prevent invalid spawning.

---

## 📁 File Structure

* `main.c`: Contains the core game loop (`runsnake`), asynchronous keyboard listening, and score tracking.
* `map2.c` / `map2.h`: Defines procedural wall placements and custom map drawing configurations.
* `map1.h`: (Optional grid layouts/alternative configurations).

---

## 🕹️ Controls & Gameplay

* **Move Up:** `W`
* **Move Down:** `S`
* **Move Left:** `A`
* **Move Right:** `D`

> **Objective:** Consume the red apples (`●`) to grow and increase your score. Avoid colliding with your own tail or the custom maze layout!

---

## 🔨 How to Build and Run (Windows)

This project requires a Windows environment due to dependencies on `<windows.h>` and console mode switching.

### Prerequisites
* A C compiler (e.g., `GCC` via MinGW, or MSVC)

### Compilation via GCC (Terminal)
```bash
gcc main.c map2.c -o SnakeGame.exe
