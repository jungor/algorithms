#ifndef MAXIMUM_SUBARRAY_H
#define MAXIMUM_SUBARRAY_H

struct subarr {
    int left;
    int right;
    int sum;
};

typedef struct subarr subarr;

subarr maximum_subarray(int nums[], int begin, int end);

#endif
