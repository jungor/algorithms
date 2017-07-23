#include "heap_sort.h"
#include "test_heap_sort.h"
#include "../utils.h"
#include <CUnit/CUnit.h>
#include <stdlib.h>

static void test_insertion_sort() {
    int len = 100;
    int nums[len];
    for (int i = 0; i < len; i++) {
        nums[i] = rand();
    }
    heap_sort(nums, len);
    for (int i = 1; i < len; i++) {
        CU_ASSERT(nums[i-1] <= nums[i]);
    }
}

CU_ErrorCode add_test_heap_sort() {
    CU_pSuite pSuite = CU_add_suite("heap_sort", NULL, NULL);
    CHECK_CU_GLOBAL();
    CU_ADD_TEST(pSuite, test_insertion_sort);
    CHECK_CU_GLOBAL();
    return CUE_SUCCESS;
}
