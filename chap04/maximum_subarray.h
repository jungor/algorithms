#ifndef MAXIMUM_SUBARRAY_H
#define MAXIMUM_SUBARRAY_H

struct MSA_slt_s {
    int left;  // 最大子数组的左端点(闭)
    int right; // 最大子数组的右端点(闭)
    int sum;   // 最大子数组的和
};

typedef struct MSA_slt_s MSA_slt_t;

enum MSA_policy_e {
    MSA_PLC_DAQ,       // 分治法
    MSA_PLC_LINEAR     // 线性时间算法
};

typedef enum MSA_policy_e MSA_policy_t;

MSA_slt_t maximum_subarray(int nums[], int begin, int end, MSA_policy_t p);

#endif
