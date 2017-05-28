#ifndef OPTIMAL_BINARY_SEARCH_TREE
#define OPTIMAL_BINARY_SEARCH_TREE

struct obst_slt_s {
    double **e;
    int **r;
    int n;
};

typedef struct obst_slt_s obst_slt_t;

void init_obst_slt(obst_slt_t *slt, int n);
void free_obst_slt(obst_slt_t *slt);
obst_slt_t optimal_bst(double p[], double q[], int n);
#endif
