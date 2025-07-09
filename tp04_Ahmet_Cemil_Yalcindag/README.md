# Playlist Manager - Stack and Queue in C

## Overview

This project implements a menu‐driven playlist manager supporting both stack (LIFO) and queue (FIFO) operations using a singly linked list in C, based on the provided header and source files :contentReference[oaicite:0]{index=0}, :contentReference[oaicite:1]{index=1}.

## Features

1. **Node Creation**  
   - **Function:** `struct node* new_Node(char* name, char* album, char* artist, int date, float duration);`  
   - Allocates and initializes a new song node.

2. **Stack Operations**  
   - **Push:** `struct node* push(struct node* top, char* name, char* album, char* artist, int date, float duration);`  
   - **Pop:** `struct node* pop(struct node* top);`  
   - **Print:** `void print_list(struct node* top);`  
   - **Search & Destroy:** `struct node* s_seek_and_destroy(struct node* top, char* name);`  
   - **Clear:** `struct node* pop_stack(struct node* top);`

3. **Queue Operations**  
   - **Enqueue:** `struct node* enqueue(struct node* head, char* name, char* album, char* artist, int date, float duration);`  
   - **Dequeue:** `struct node* dequeue(struct node* head);`  
   - **Search & Destroy:** `struct node* q_seek_and_destroy(struct node* head, char* name);`  
   - **Clear:** `int erase_queue(struct node* head);`

4. **Search Utility**  
   - **Function:** `int search_node(struct node* list, char* name);`  
   - Checks for the existence of a song by name and prints the result.

## Getting Started

### Prerequisites

- A C compiler supporting C11 (e.g. `gcc`)  
- A POSIX‐compatible environment (Linux, macOS, or WSL)

### Building

```sh
gcc -Wall -Wextra -std=c11 -o playlist main.c catalog.c
```

### Running

```sh
./playlist
```
