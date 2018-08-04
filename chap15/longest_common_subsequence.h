#ifndef LONGEST_COMMON_SUBSEQUENCE_H
#define LONGEST_COMMON_SUBSEQUENCE_H

enum lcs_slt_dirc_e {
    UP,
    LEFT,
    UP_LEFT
};

typedef enum lcs_slt_dirc_e lcs_slt_dirc_t;

struct lcs_slt_s {
    int **c;
    lcs_slt_dirc_t **b;
    int m;
    int n;
};

typedef struct lcs_slt_s lcs_slt_t;

void init_lcs_slt(lcs_slt_t *slt, int m, int n);
void free_lcs_slt(lcs_slt_t *slt);
lcs_slt_t lcs_length(const char *strx, const char *stry);
void get_lcs(const char *strx, const char *stry, int i, int j, char *buf);

#endif
