#ifndef RADIX_SORT
#define RADIX_SORT

#include <limits.h>
#include <stdio.h>
#include <math.h>
#define RADIX_SORT_NUM_MAX_WIDTH ((int)floor((log(abs(INT_MAX))/(log(10)))) + 1)
void radix_sort(int nums[], int len);
#endif
