#include "longest_common_subsequence.h"
#include "test_longest_common_subsequence.h"
#include "../utils.h"
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <stdio.h>
#include <stdlib.h>

static int InitSuite() {
    return 0;
}

static int EndSuite() {
    return 0;
}

static void test_lcs() {
    const char *str1 = "ABCBDAB";
    const char *str2 = "BDCABA";
    const char *lcs = "BCBA";
    char buf[512];
    get_lcs(str1, str2, strlen(str1), strlen(str2), buf);
    CU_ASSERT(strlen(buf) == strlen(lcs));
    CU_ASSERT(strncmp(buf, lcs, 4) == 0);
}

CU_ErrorCode add_test_lcs() {
    CU_pSuite pSuite = NULL;

    /***************
     * 1. CU_add_suite 增加一个Suite
     * 2. Suite名字 : testSuite
     * 3. InitSuite EndSuite：分别是测试单元初始和释放函数，如不需要则NULL传递
     ****************/
    pSuite = CU_add_suite("lcs", InitSuite, EndSuite);
    CHECK_CU_GLOBAL();

    /***************
     * 1. 注册当前Suite下的测试用例　
     * 2. pSuite：用例指针
     * 3. "Test1"： 测试单元名称
     * 4. Test1：测试函数
     ***************/
    CU_ADD_TEST(pSuite, test_lcs);
    CHECK_CU_GLOBAL();

    return CUE_SUCCESS;
}
