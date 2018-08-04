#include "cut_rod.h"
#include "test_cut_rod.h"
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

static void test_cut_rod() {
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    CU_ASSERT(cut_rod(p, 1) == 1);
    CU_ASSERT(cut_rod(p, 2) == 5);
    CU_ASSERT(cut_rod(p, 3) == 8);
    CU_ASSERT(cut_rod(p, 4) == 10);
    CU_ASSERT(cut_rod(p, 5) == 13);
    CU_ASSERT(cut_rod(p, 6) == 17);
    CU_ASSERT(cut_rod(p, 7) == 18);
    CU_ASSERT(cut_rod(p, 8) == 22);
    CU_ASSERT(cut_rod(p, 9) == 25);
    CU_ASSERT(cut_rod(p, 10) == 30);
}

CU_ErrorCode add_test_cut_rod() {
    CU_pSuite pSuite = NULL;

    /***************
     * 1. CU_add_suite 增加一个Suite
     * 2. Suite名字 : testSuite
     * 3. InitSuite EndSuite：分别是测试单元初始和释放函数，如不需要则NULL传递
     ****************/
    pSuite = CU_add_suite("cut_rod", InitSuite, EndSuite);
    CHECK_CU_GLOBAL();

    /***************
     * 1. 注册当前Suite下的测试用例　
     * 2. pSuite：用例指针
     * 3. "Test1"： 测试单元名称
     * 4. Test1：测试函数
     ***************/
    CU_ADD_TEST(pSuite, test_cut_rod);
    CHECK_CU_GLOBAL();

    return CUE_SUCCESS;
}
