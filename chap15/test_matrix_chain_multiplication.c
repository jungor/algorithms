#include "matrix_chain_multiplication.h"
#include "test_matrix_chain_multiplication.h"
#include "../utils.h"
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <stdio.h>

static int InitSuite() {
    return 0;
}

static int EndSuite() {
    return 0;
}

static void test_matrix_chain_multi() {
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    mcm_slt_t slt = matrix_chain_order(p, 7);
    CU_ASSERT_EQUAL(slt.m[1][6] , 15125);
    free_mcm_slt(slt);
}

CU_ErrorCode add_test_matrix_chain_multi() {
    CU_pSuite pSuite = NULL;

    /***************
     * 1. CU_add_suite 增加一个Suite
     * 2. Suite名字 : testSuite
     * 3. InitSuite EndSuite：分别是测试单元初始和释放函数，如不需要则NULL传递
     ****************/
    pSuite = CU_add_suite("matrix_chain_multi", InitSuite, EndSuite);
    CHECK_CU_GLOBAL();

    /***************
     * 1. 注册当前Suite下的测试用例　
     * 2. pSuite：用例指针
     * 3. "Test1"： 测试单元名称
     * 4. Test1：测试函数
     ***************/
    CU_ADD_TEST(pSuite, test_matrix_chain_multi);
    CHECK_CU_GLOBAL();

    return CUE_SUCCESS;
}
