#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// prints out all elements in the array
void output_array(Array *a)
{
  if (a == NULL || a->data == NULL) {
    printf("Error: Array is NULL\n");
    return;
  }

  printf("Array (size %d): ", a->size);
  for (int i = 0; i < a->size; i++) {
    printf("%.2f ", a->data[i]);
  }
  printf("\n");
}

// shifts all elements to the left by 1
// first element wraps around to the end
void shift_array(Array *a)
{
  if (a == NULL || a->data == NULL || a->size == 0) {
    return;
  }

  // save first element so we don't lose it
  double temp = a->data[0];
  
  // move everything one spot to the left
  for (int i = 0; i < a->size - 1; i++) {
    a->data[i] = a->data[i + 1];
  }
  
  // put the first element at the end
  a->data[a->size - 1] = temp;
}

// averages adjacent elements and returns a new array
// new array is half the size. if odd size, last element ignored
Array *average_adjacent(Array *a)
{
  if (a == NULL || a->data == NULL) {
    return NULL;
  }

  // divide by 2 to get new size (handles odd arrays automatically)
  int new_size = a->size / 2;
  
  // create new Array structure
  Array *new_array = (Array *)malloc(sizeof(Array));
  new_array->size = new_size;
  new_array->data = (double *)malloc(new_size * sizeof(double));

  // average pairs of adjacent elements
  for (int i = 0; i < new_size; i++) {
    new_array->data[i] = (a->data[2 * i] + a->data[2 * i + 1]) / 2.0;
  }

  return new_array;
}

int main(int argc, char *argv[])
{
  // check if user gave us an array size
  if (argc != 2) {
    printf("Usage: %s <array_size>\n", argv[0]);
    return 1;
  }

  // convert the string argument to an integer
  int size = atoi(argv[1]);
  
  // make sure size is valid
  if (size <= 0) {
    printf("Error: Array size must be a positive integer\n");
    return 1;
  }

  // allocate memory for the Array struct
  Array *my_array = (Array *)malloc(sizeof(Array));
  if (my_array == NULL) {
    printf("Error: Failed to allocate memory for Array structure\n");
    return 1;
  }

  // allocate memory for the data array
  my_array->size = size;
  my_array->data = (double *)malloc(size * sizeof(double));
  if (my_array->data == NULL) {
    printf("Error: Failed to allocate memory for array data\n");
    free(my_array);
    return 1;
  }

  // fill the array with values 0 to size-1
  // this makes it easy to see if shift and average are working
  for (int i = 0; i < size; i++) {
    my_array->data[i] = (double)i;
  }

  // test the three functions
  printf("--- Original Array ---\n");
  output_array(my_array);

  printf("\n--- After Shift ---\n");
  shift_array(my_array);
  output_array(my_array);

  printf("\n--- Averaged Adjacent Pairs ---\n");
  Array *averaged = average_adjacent(my_array);
  output_array(averaged);

  // free all the memory we allocated
  free(my_array->data);
  free(my_array);
  free(averaged->data);
  free(averaged);

  return 0;
}


