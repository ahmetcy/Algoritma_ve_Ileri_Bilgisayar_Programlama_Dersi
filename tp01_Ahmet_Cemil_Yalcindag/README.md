# 2D Geometry Operations in C


## Overview

This project is an exercise in the C programming language that reinforces your understanding of `struct`s and `pointer`s by implementing basic two‐dimensional geometry operations via standalone functions.

## Features

1. **Data Structures**  
   - Define a `struct Point { int x, y; }` to represent a point in the plane.  
   - Define a `struct Rectangle { struct Point top_left; struct Point bottom_right; }` to represent an axis‐aligned rectangle.  

2. **Pointer Initialization**  
   - Use pointers to set the initial values of `Point` and `Rectangle` instances.  

3. **Point Operations**  
   - `bool same_points(const struct Point *p1, const struct Point *p2);`  
     Check whether two points have the same coordinates.  
   - `struct Point sum_points(const struct Point *p1, const struct Point *p2);`  
     Return a new point representing the coordinate‐wise sum of two points.  

4. **Point‐in‐Rectangle Test**  
   - `bool point_in_rectangle(const struct Point *p, const struct Rectangle *r);`  
     Determine whether a given point lies inside (or on the boundary of) an axis‐aligned rectangle.  

5. **Rectangle Construction**  
   - `struct Rectangle point_to_rectangle(const struct Point *p1, const struct Point *p2);`  
     Build a rectangle from two opposite‐corner points.  

6. **Demonstration in `main()`**  
   - Create example points and rectangles.  
   - Test each function above and print clear, labeled results to the console.

## Getting Started

### Prerequisites

- A C compiler (e.g. `gcc`)
- A POSIX‐compatible shell (Linux, macOS, or WSL on Windows)

### Building

```sh
gcc -Wall -Wextra -std=c11 -o geometry main.c
```
### Running

```sh
./geometry


