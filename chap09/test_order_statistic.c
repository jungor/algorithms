#include "order_statistic.h"
#include "test_order_statistic.h"
#include "../utils.h"
#include <CUnit/CUnit.h>
#include <stdlib.h>

static void test_order_statistic() {
    int len = 100;
    int nums[len];
    for (int i = 0; i < len; i++) {
        nums[i] = i;
    }
    shuffle(nums, len);
    CU_ASSERT(maximum(nums, len) == len-1);
    CU_ASSERT(minimum(nums, len) == 0);
    for (int i = 0; i < 10; i++) {
        // CU_ASSERT(randomized_select(nums, 0, len, i) == i);
        int rst = linear_select(nums, 0, len, i);
        // printf("expect: %d, actually: %d\n", i, rst);
        CU_ASSERT_EQUAL(rst, i);
    }
}

CU_ErrorCode add_test_order_statistic() {
    CU_pSuite pSuite = CU_add_suite("order_statistic", NULL, NULL);
    CHECK_CU_GLOBAL();
    CU_ADD_TEST(pSuite, test_order_statistic);
    CHECK_CU_GLOBAL();
    return CUE_SUCCESS;
}
