# Cub3D - 3D Maze Renderer with Raycasting

Cub3D is a graphics project that brings a 3D maze to life from a first-person perspective using raycasting principles.

## Introduction

Cub3D is a project that utilizes the C programming language, the miniLibX graphics library, and the concept of raycasting to create a 3D maze renderer. This project aims to explore the practical applications of mathematics and algorithms while improving skills in graphics, events handling, and more.
Prerequisites

To run Cub3D, you need the following:

    A system with macOS or Linux (for miniLibX compatibility)
    GCC (GNU Compiler Collection)
    MiniLibX (a graphics library for creating graphical applications)

Getting Started

    Clone this repository to your local machine:

```bash

git clone https://github.com/fiborges/42SchoolProjects/cub3D.git
```
    Navigate to the project directory:

```bash

cd cub3D
```
    Compile the project using the provided Makefile:

```bash

make
```
    Run the program with a map file as an argument:

```bash

./cub3D path_to_map.cub
```

## How Cub3D Works
### Raycasting

Raycasting is the fundamental technique behind Cub3D's 3D rendering. It simulates a player's perspective in a maze by casting rays from the player's position and calculating distances to the maze walls. This creates the illusion of depth and perspective.
Map Rendering

Cub3D reads a map from a .cub file, where characters represent walls, empty spaces, and the player's starting position and orientation. The program parses this file and renders the map in a 3D view, allowing the player to explore the maze.
Player Movement

The player can navigate through the maze using the W, A, S, and D keys to move forward, left, backward, and right, respectively. The arrow keys enable the player to look left and right. To exit the program, press the ESC key or click the window's red cross.
Compiling and Running Cub3D

Cub3D can be compiled using the provided Makefile, and it should be run with a map file as an argument:

```bash

./cub3D path_to_map.cub
```
### Raycasting in Detail

Raycasting is at the core of creating the 3D maze effect in Cub3D. Here's a more detailed explanation of how it works:
Basic Raycasting Algorithm

    Initialize player position and direction.
    Cast a ray for each vertical stripe on the screen.
    For each ray, find the closest wall by checking intersections with the maze grid.
    Calculate the distance from the player to the wall.
    Use the distance to determine the wall's height on the screen.
    Draw the wall slice on the screen.

Calculating Wall Distances

To calculate wall distances efficiently, you can use the following equations:

    Ray's X direction: rayDirX = cos(playerDirection)
    Ray's Y direction: rayDirY = sin(playerDirection)
    Step size for X and Y based on ray direction:
        deltaX = sqrt(1 + (rayDirY / rayDirX) ^ 2)
        deltaY = sqrt(1 + (rayDirX / rayDirY) ^ 2)
    Initial side distance:
        sideDistX = (playerX - mapX) * deltaX
        sideDistY = (playerY - mapY) * deltaY

Drawing the Projection

To draw the 3D projection of the walls, use the following formula:

    Wall height on the screen: lineHeight = screen_height / wall_distance
    Calculate the top and bottom pixel for the wall slice on the screen:
        drawStart = -lineHeight / 2 + screen_height / 2
        drawEnd = lineHeight / 2 + screen_height / 2

Controls

    Arrow keys: Look left and right
    W: Move forward
    A: Move left
    S: Move backward
    D: Move right
    ESC: Quit the program

#### Examples

For a better understanding of Cub3D's raycasting in action, consider the provided examples in the source code. You'll find practical code implementations of the raycasting algorithm, including intersection calculations, distance measurements, and wall rendering.
Contributing

This project is a part of my learning process. If you'd like to contribute or provide feedback, feel free to create an issue or a pull request.

Project made with @snowhp!! 
