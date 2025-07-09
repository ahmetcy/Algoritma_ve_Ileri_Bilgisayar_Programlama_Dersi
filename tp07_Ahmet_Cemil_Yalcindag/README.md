# TP07 - Simple Sorting Algorithms in C

## Overview

This project implements the simple sorting algorithms (Bubble Sort, Selection Sort, and Insertion Sort) as specified in the TP07 assignment “Algorithmes de Tri Simples” :contentReference[oaicite:0]{index=0}, using the source code in `tp07_Ahmet_Cemil_Yalcindag.c` :contentReference[oaicite:1]{index=1}. It sorts a fixed array of integers corresponding to the letters of “ALGORITHM” and prints the results of each algorithm.

## Features

1. **Bubble Sort**  
   - **Function:** `void bubbleSort(int array[], int n);`  
   - Repeatedly compares adjacent elements and swaps them if they are in the wrong order. Prints the sorted array after completion.

2. **Selection Sort**  
   - **Function:** `void selectionSort(int array[], int len);`  
   - Selects the minimum element from the unsorted portion and swaps it with the first unsorted element, iterating through the array. Prints the sorted array after completion.

3. **Insertion Sort**  
   - **Function:** `void insertionSort(int array[], int len);`  
   - Builds the sorted array one element at a time by inserting each element into its correct position within the sorted portion. Prints the sorted array after completion.

## Getting Started

### Prerequisites

- A C compiler supporting C11 (e.g., `gcc`)  
- A POSIX-compatible environment (Linux, macOS, or WSL)

### Building

```sh
gcc -Wall -Wextra -std=c11 -o tp07 tp07_Ahmet_Cemil_Yalcindag.c
```

### Running
Run the executable to perform all three sorts on the predefined array `{1, 12, 7, 15, 18, 9, 20, 8, 13}` (mapping to “ALGORITHM”):
```sh
./tp07
```
