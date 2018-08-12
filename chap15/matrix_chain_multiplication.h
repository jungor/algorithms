#ifndef MATRIX_CHAIN_MULTIPLICATION
#define MATRIX_CHAIN_MULTIPLICATION

struct mcm_slt_s {
    int **s;
    int **m;
    int len;
};

typedef struct mcm_slt_s mcm_slt_t;

void free_mcm_slt(mcm_slt_t slt);
void print_optimal_parens(int p[], int n, int i, int j);
mcm_slt_t matrix_chain_order(int p[], int n);

#endif
