#include "optimal_binary_search_tree.h"
#include "../utils.h"
#include <CUnit/CUnit.h>
#include <CUnit/console.h>
#include <stdio.h>

static int InitSuite() {
    return 0;
}

static int EndSuite() {
    return 0;
}

static void test_optimal_bst() {
    double p[] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
    double q[] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    int n = 5;
    obst_slt_t slt = optimal_bst(p, q, n);
    CU_ASSERT(slt.e[1][n] == 2.75);
}

CU_ErrorCode add_test_obst() {
    CU_pSuite pSuite = NULL;

    /***************
     * 1. CU_add_suite 增加一个Suite
     * 2. Suite名字 : testSuite
     * 3. InitSuite EndSuite：分别是测试单元初始和释放函数，如不需要则NULL传递
     ****************/
    pSuite = CU_add_suite("TestOBST", InitSuite, EndSuite);
    CHECK_CU_GLOBAL();

    /***************
     * 1. 注册当前Suite下的测试用例　
     * 2. pSuite：用例指针
     * 3. "Test1"： 测试单元名称
     * 4. Test1：测试函数
     ***************/
    CU_ADD_TEST(pSuite, test_optimal_bst);
    CHECK_CU_GLOBAL();

    return CUE_SUCCESS;
}
