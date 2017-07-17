#include "chap02/test_insertion_sort.h"
#include "chap02/test_merge_sort.h"
#include "chap04/test_maximum_subarray.h"
#include "chap15/test_optimal_binary_search_tree.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <CUnit/Console.h>

int main() {
    srand(time(NULL));
    //CU_initialize_registry 注册函数注册一个用例返回CUE_系列异常值
    int cu_res;
    cu_res = CU_initialize_registry();
    CHECK_CU_RETURN(cu_res);

    //CU_get_registry 返回注册到用例指针
    //assert(NULL != CU_get_registry());

    //检测是否在执行
    //assert(!CU_is_test_running());

    //注册各个suite
    CHECK_CU_RETURN(add_test_insertion_sort());
    CHECK_CU_RETURN(add_test_merge_sort());
    CHECK_CU_RETURN(add_test_maximum_subarray());
    CHECK_CU_RETURN(add_test_obst());

    //使用console控制交互界面的函数入口
    CU_console_run_tests();

    /***使用自动产生XML文件的模式********
      CU_set_output_filename("TestMax");
      CU_list_tests_to_file();
      CU_automated_run_tests();
     ***********************************/

    //调用完毕清除注册信息
    CU_cleanup_registry();

    return 0;
}
