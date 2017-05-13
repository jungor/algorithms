#include "utils.h"
#include "chap02/insertion_sort.h"
#include "chap02/merge_sort.h"
#include "chap04/maximum_subarray.h"
#include "chap06/heap_sort.h"
#include <stdio.h>

int main() {
    //int nums[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int nums[] = {1, 0, 4, 3, 7, 6, 5, 2, 9, 8};
    heap_sort(nums, 10);
    // subarr sa = maximum_subarray(nums, 0, 4);
    print_array(nums, 10);
    //printf("left: %d, right: %d, sum: %d\n", sa.left, sa.right, sa.sum);
    return 0;
}
