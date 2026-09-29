# Assignment3_ECE231_L
# Assignment 3: Custom Array Structure

## Overview
This program impliments a custom array data structures that stores both the size and data together. It shows dynamic memory allocation, passing structs to functions, and manipuleting array data.

## What's Implemented
- **Array Structure** (`array.h`): Combines size and dynamic data array into one struct
- **output_array()**: Prints all elements in the array
- **shift_array()**: Shifts elements left by 1, wraps first element to end
- **average_adjacent()**: Creates a new array by averaging adjecent pairs from original

## How to Compile and Run

Compile:
```bash
gcc -o main main.c

Run with array size argument:
```bash
./main 10

## Files
- `array.h` - Structure definition and function declarations
- `main.c` - Implimentation of functions and main program
- `README.md` - This file

## Notes
- Program validates command line input (must be positive integer)
- All allocated memory is freed at the end
- Original array is modified by shift_array()
- average_adjacent() returns a newly allocated array that must be freed
