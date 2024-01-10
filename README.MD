# Simple Game in C++ using Raylib

This C++ code implements a simple game using the Raylib library. The game features a moving circle controlled by the user and an axe that moves around the screen. The goal is to avoid collisions with the moving axe.

## Setup and Initialization

- `#include <iostream>`: Include the necessary libraries for input and output.
- `#include "raylib.h"`: Include the Raylib library for graphics.
- Initialize window dimensions and title using `InitWindow`.
- Define variables for circle and axe attributes, movement speeds, and collision flags.

## Game Loop

- `SetTargetFPS(60)`: Set the frames per second to 60.
- Enter the game loop using `while (!WindowShouldClose())`.

## Player Logic

- Draw the circle based on its attributes using `DrawCircle`.
- Update circle position based on user input (W, A, S, D) for movement.
- Implement wrapping logic to keep the circle within the window boundaries.

## Enemy Logic

- Draw the axe using `DrawRectangle`.
- Update axe position and implement wrapping logic.
- Randomly modify movement directions using `GetRandomValue`.
- Speed up the axe periodically after a certain time (`timer % 120`).
- Calculate hitboxes for the circle and axe.
- Check for collisions along the X and Y axes.

## Collision Detection and Output

- Display "Game Over!" when collisions occur.
- Output debug information, including hitbox coordinates and gameplay duration, to the console.
- Continue displaying gameplay statistics such as the timer, axe movement speed, and duration.

## Conclusion

This code provides a simple game scenario with a moving circle and axe, demonstrating basic game development concepts using the Raylib library in C++.