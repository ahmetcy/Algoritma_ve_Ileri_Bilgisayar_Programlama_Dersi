# TP02 - Dynamic Memory Management in C

## Overview

This project implements the dynamic memory management exercises (Ex1–Ex4) from the TP02 assignment PDF :contentReference[oaicite:0]{index=0}, using the provided skeleton code :contentReference[oaicite:1]{index=1}. It covers pointer-based value modification, heap allocation, reallocation, and proper deallocation in C.

## Features

1. **Ex1: Pointer-based Value Modification**  
   - **Function:** `void ex1_square(int *number);`  
   - Squares the integer pointed to by `number` via pointer dereferencing.

2. **Helper Functions**  
   - `void print_array(int *array, int size);`  
     Prints `size` elements of the integer array.  
   - `double mean_array(int *array, int size);`  
     Computes and returns the arithmetic mean of the array elements.

3. **Ex2: Dynamic Array Creation**  
   - **Function:** `void ex2(void);`  
   - Prompts the user for an array size, allocates memory with `malloc()`, and checks for allocation failure.  
   - Fills the array with random integers in [0, 100], prints the array and its mean, then frees the memory.

4. **Ex3: Array Resizing and Reallocation**  
   - **Function:** `void ex3(void);`  
   - Prompts for a new array size, uses `realloc()` to adjust the size, initializes any new elements to `-1`, and prints the resized array.

5. **Ex4: Command-line Parameter-Driven Allocation**  
   - **Function:** `void ex4(int n);`  
   - Reads `n` from `argv[1]`; if missing, prints an error message.  
   - Allocates an array of size `n`, fills it with random values, prints it, computes its mean, and frees the memory.

## Getting Started

### Prerequisites

- A C compiler supporting C11 (e.g. `gcc`)  
- A POSIX-compatible environment (Linux, macOS, or WSL)

### Building

```sh
gcc -Wall -Wextra -std=c11 -o tp02 tp02_Ahmet_Cemil_Yalcindag.c
```

### Running
**Without arguments** (runs Ex1–Ex3; Ex4 will print an error if no size is provided):

```sh
./tp02
```

**With a size argument** (runs Ex1–Ex4, using the provided size for Ex4):

```sh
./tp02 8
```

