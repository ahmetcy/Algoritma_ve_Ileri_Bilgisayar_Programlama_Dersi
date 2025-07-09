# TP03 - Polynomial Linked List in C

## Overview

This project implements polynomial operations using a singly linked list in C as specified in the TP03 assignment. It provides functions to:

- Generate a random polynomial of a given length  
- Print the polynomial in human-readable form  
- Compute the number of terms  
- Find the term with the maximum coefficient  
- Find the term with the highest degree  
- Build a polynomial from a fixed array of coefficients  

## Features

1. **Random Polynomial Creation**  
   - **Function:** `struct polynom* create_random_list(int length);`  
   - Generates a linked list with `length` nodes. Each node’s `factor` is a random integer in [1,9], and `degree` runs from 0 to `length-1`.

2. **Polynomial Printing**  
   - **Function:** `void print_polynom(struct polynom *head);`  
   - Prints terms in the form `a*x^d + b*x^e + …`.

3. **Length Calculation**  
   - **Function:** `int get_length(struct polynom *head);`  
   - Returns the total count of nodes (terms) in the list.

4. **Find Maximum Coefficient Term**  
   - **Function:** `struct polynom* get_element_max_factor(struct polynom *head);`  
   - Traverses the list and returns the node whose `factor` is largest.

5. **Find Highest Degree Term**  
   - **Function:** `struct polynom* get_element_max_degree(struct polynom *head);`  
   - Traverses the list and returns the node whose `degree` is largest.

6. **Array-to-Polynomial Conversion**  
   - **Function:** `struct polynom* array_to_list(int *array, int length);`  
   - Constructs a polynomial linked list from the given coefficient array, assigning degrees sequentially from 0.

## Getting Started

### Prerequisites

- A C compiler supporting C11 (e.g., `gcc`)  
- A POSIX-compatible environment (Linux, macOS, or WSL)

### Building

Compile the source files into an executable named `tp03`:

```sh
gcc -Wall -Wextra -std=c11 -o tp03 main.c polynom.c
```

### Running

```sh
./tp03
```
