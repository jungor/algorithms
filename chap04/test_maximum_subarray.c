#include "test_maximum_subarray.h"
#include "maximum_subarray.h"
#include "../utils.h"
#include <CUnit/CUnit.h>
#include <stdlib.h>

static void test_maximum_subarray() {
    int nums[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    MSA_slt_t slt = maximum_subarray(nums, 0, sizeof(nums)/sizeof(int), MSA_PLC_DAQ);
    CU_ASSERT_EQUAL(slt.left, 7);
    CU_ASSERT_EQUAL(slt.right, 10);
    CU_ASSERT_EQUAL(slt.sum, 43);
    slt = maximum_subarray(nums, 0, sizeof(nums)/sizeof(int), MSA_PLC_LINEAR);
    CU_ASSERT_EQUAL(slt.left, 7);
    CU_ASSERT_EQUAL(slt.right, 10);
    CU_ASSERT_EQUAL(slt.sum, 43);
    int nums2[] = {1, 2, -3, 1};
    slt = maximum_subarray(nums2, 0, sizeof(nums2)/sizeof(int), MSA_PLC_LINEAR);
    printf("%d, %d, %d\n", slt.left, slt.right, slt.sum);
    CU_ASSERT_EQUAL(slt.left, 0);
    CU_ASSERT_EQUAL(slt.right, 1);
    CU_ASSERT_EQUAL(slt.sum, 3);
}

CU_ErrorCode add_test_maximum_subarray() {
    CU_pSuite pSuite = CU_add_suite("maximum_subarray", NULL, NULL);
    CHECK_CU_GLOBAL();
    CU_ADD_TEST(pSuite, test_maximum_subarray);
    CHECK_CU_GLOBAL();
    return CUE_SUCCESS;
}
