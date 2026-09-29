#ifndef ARRAY_H
#define ARRAY_H

struct _my_array
{
  int size;
  double *data;
};
typedef struct _my_array Array;

// Function declarations
void output_array(Array *a);
void shift_array(Array *a);
Array *average_adjacent(Array *a);

#endif
