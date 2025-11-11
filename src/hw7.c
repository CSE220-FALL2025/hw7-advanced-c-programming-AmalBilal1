#include "hw7.h"

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root) {
    return NULL;
}

matrix_sf* find_bst_sf(char name, bst_sf *root) {
    return NULL;
}

void free_bst_sf(bst_sf *root) {
}

matrix_sf* add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    matrix_sf *result = malloc(sizeof(matrix_sf) + mat1->num_rows*mat1->num_cols*sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    result -> name = '!';
    result -> num_rows = mat1 -> num_rows;
    result -> num_cols = mat1 -> num_cols;
    int length = result -> num_cols * result -> num_rows;
    for (int i = 0; i < length; i++) {
        result -> values[i] = mat1 -> values[i] + mat2 -> values[i];
    }
    return result;
}

matrix_sf* mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    matrix_sf *result = malloc(sizeof(matrix_sf) + mat1->num_rows*mat2->num_cols*sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    result -> name = '!';
    result -> num_rows = mat1 -> num_rows;
    result -> num_cols = mat2 -> num_cols;

    for (int i = 0; i < result->num_rows; i++) {
        for (int j = 0; j < result->num_cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat2->num_rows; k++) {
                sum += mat1 -> values[i * mat1 -> num_cols + k] * mat2 -> values[k * mat2 -> num_cols + j]; // row i (mat1) * col j (mat2)
            }
            result -> values[i * result -> num_cols + j] = sum;
        }
    }
    
    return result;
}

matrix_sf* transpose_mat_sf(const matrix_sf *mat) {
    matrix_sf *result = malloc(sizeof(matrix_sf) + mat->num_rows*mat->num_cols*sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    result -> name = '!';
    result -> num_rows = mat -> num_cols;
    result -> num_cols = mat -> num_rows;
    for (int i = 0; i < result -> num_rows; i++) {
        for (int j = 0; j < result -> num_cols; j++) {
            result -> values[i * result -> num_cols + j] = mat -> values[j * mat -> num_cols + i];
        }
    }
    return result;
}

matrix_sf* create_matrix_sf(char name, const char *expr) {
    return NULL;
}

char* infix2postfix_sf(char *infix) {
    return NULL;
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    return NULL;
}

matrix_sf *execute_script_sf(char *filename) {
   return NULL;
}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, int values[]) {
    matrix_sf *m = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows*num_cols*sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat) {
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows*mat->num_cols; i++) {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows*mat->num_cols-1)
            printf(" ");
    }
    printf("\n");
}
