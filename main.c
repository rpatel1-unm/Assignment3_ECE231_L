#include <stdio.h>
#include <stdlib.h>
#include "array.h"

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

void shift_array(Array *a)
{
  if (a == NULL || a->data == NULL || a->size == 0) {
    return;
  }

  double temp = a->data[0];
  for (int i = 0; i < a->size - 1; i++) {
    a->data[i] = a->data[i + 1];
  }
  a->data[a->size - 1] = temp;
}

Array *average_adjacent(Array *a)
{
  if (a == NULL || a->data == NULL) {
    return NULL;
  }

  int new_size = a->size / 2;
  Array *new_array = (Array *)malloc(sizeof(Array));
  new_array->size = new_size;
  new_array->data = (double *)malloc(new_size * sizeof(double));

  for (int i = 0; i < new_size; i++) {
    new_array->data[i] = (a->data[2 * i] + a->data[2 * i + 1]) / 2.0;
  }

  return new_array;
}

int main(int argc, char *argv[])
{
  // Check command line arguments
  if (argc != 2) {
    printf("Usage: %s <array_size>\n", argv[0]);
    return 1;
  }

  // Parse and validate size
  int size = atoi(argv[1]);
  if (size <= 0) {
    printf("Error: Array size must be a positive integer\n");
    return 1;
  }

  // Allocate structure
  Array *my_array = (Array *)malloc(sizeof(Array));
  if (my_array == NULL) {
    printf("Error: Failed to allocate memory for Array structure\n");
    return 1;
  }

  // Set size and allocate data
  my_array->size = size;
  my_array->data = (double *)malloc(size * sizeof(double));
  if (my_array->data == NULL) {
    printf("Error: Failed to allocate memory for array data\n");
    free(my_array);
    return 1;
  }

  // Fill array with values (0 to size-1)
  for (int i = 0; i < size; i++) {
    my_array->data[i] = (double)i;
  }

  // Step 4: Test functions
  printf("--- Original Array ---\n");
  output_array(my_array);

  printf("\n--- After Shift ---\n");
  shift_array(my_array);
  output_array(my_array);

  printf("\n--- Averaged Adjacent Pairs ---\n");
  Array *averaged = average_adjacent(my_array);
  output_array(averaged);

  // Free memory
  free(my_array->data);
  free(my_array);
  free(averaged->data);
  free(averaged);

  return 0;
}
