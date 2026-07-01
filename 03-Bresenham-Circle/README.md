# Bresenham Circle Drawing Algorithm (OpenGL GLUT)

This project demonstrates the Bresenham Circle Drawing Algorithm using C++ and OpenGL GLUT.

## Objective

Draw a circle efficiently using only integer arithmetic.

## Features

- Draws a circle using Bresenham's Algorithm
- Uses OpenGL GLUT
- Fast and accurate raster graphics algorithm
- Educational implementation

## Algorithm

1. Input the radius of the circle.
2. Set the center coordinates.
3. Initialize:
   - x = 0
   - y = radius
   - d = 3 - 2 × radius
4. Plot the eight symmetric points.
5. Repeat until x ≤ y:
   - If d < 0
     - d = d + 4x + 6
   - Else
     - d = d + 4(x − y) + 10
     - y--
   - x++
   - Plot symmetric points.
6. Display the circle.

## Requirements

- C++
- OpenGL
- GLUT / FreeGLUT

## Output

See `output.png`
