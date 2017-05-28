#include "utils.h"
#include "chap02/insertion_sort.h"
#include "chap02/merge_sort.h"
#include "chap04/maximum_subarray.h"
#include "chap06/heap_sort.h"
#include "chap07/quick_sort.h"
#include "chap08/counting_sort.h"
#include "chap08/radix_sort.h"
#include "chap09/order_statistic.h"
#include "chap15/cut_rod.h"
#include "chap15/matrix_chain_multiplication.h"
#include "chap15/longest_common_subsequence.h"
#include "chap15/optimal_binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    //int nums[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    //int nums[10] = {1, 0, 4, 3, 7, 6, 5, 2, 9, 8};
    int nums[] = {
        71, 57, 79,  0, 60, 56, 89, 92, 87, 18,
        43, 53, 86, 26, 15, 51, 73, 65, 41, 42,
        25, 62, 49, 28, 70, 78,  5, 85, 22, 69,
         6, 93, 37,  4, 40, 38, 77, 64, 76, 63,
        94, 33, 21, 29, 35, 11, 12, 97, 48,  7,
        17, 91, 99,  8, 44, 24, 39, 83,  3, 52,
        90, 95,  2, 10, 58, 88, 27, 14, 75, 98,
        66,  9, 68, 67, 55, 50, 16, 45, 59, 20,
        54, 72, 32, 19, 84, 47,  1, 80, 13, 36,
        34, 96, 81, 31, 46, 30, 61, 23, 74, 82
    };
    // int nums[] = {49, 26, 64, 97, 59, 62, 76, 12, 76, 20, 5, 66, 60, 0, 28, 59, 9, 43, 5, 44, 27, 80, 80, 27, 10, 10, 14, 86, 7, 37, 39, 12, 27, 40, 46, 96, 93, 38, 11, 27, 56, 6, 75, 85, 12, 50, 49, 75, 63, 12, 11, 71, 28, 38, 0, 53, 96, 2, 99, 58, 85, 81, 88, 60, 73, 15, 86, 72, 63, 58, 47, 28, 59, 96, 62, 86, 73, 92, 50, 46, 60, 2, 23, 8, 42, 5, 11, 63, 60, 14, 50, 72, 28, 48, 82, 17, 15, 22, 68, 29};
    //int p[] = {30,35,15,5,10,20,25};
    //const char *strx = "ABCBDAB";
    //const char *stry = "BDCABA";
    //print_lcs(strx, stry, 7, 6);
    //print_optimal_parens(p, 6, 2, 5);
    //int price_table[] = {0,1,5,8,9,10,17,17,20,24,30};
    //print_array(nums, 100);
    //int s = linear_select(nums, 0, 100, 10);
    //radix_sort(nums, 100);
    // subarr sa = maximum_subarray(nums, 0, 4);
    //print_array(nums, 100);
    //for (int i = 1; i <= 10; i++) {
    //    int s = memoized_cut_rod(price_table, i);
    //    int t = bottom_up_cut_rod(price_table, i);
    //    printf("%d %d\n", s, t);
    //    print_cut_rod_solution(price_table, i);
    //}
    //printf("left: %d, right: %d, sum: %d\n", sa.left, sa.right, sa.sum);
    double p[] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
    double q[] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    optimal_bst(p, q, 5);
    return 0;
}
