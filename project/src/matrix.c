#include <matrix.h>

// Init/release operations
Matrix* create_matrix_from_file(const char* path_file) {
    FILE * file = fopen(path_file, "r");

    if (file != NULL) {
        Matrix * pMatrix_from_file = NULL;
        pMatrix_from_file = malloc(sizeof(Matrix));
        fscanf(file, "%zu%zu", &pMatrix_from_file->rows, &pMatrix_from_file->cols);
        pMatrix_from_file->matr_data =
            malloc(sizeof(*(pMatrix_from_file->matr_data))*pMatrix_from_file->cols);
        for (size_t i = 0; i < pMatrix_from_file->cols; i++) {
            (pMatrix_from_file->matr_data)[i] =
                malloc(sizeof(**(pMatrix_from_file->matr_data))*pMatrix_from_file->rows);
        }
        for (size_t j = 0; j < pMatrix_from_file->rows; j++) {
            for (size_t i = 0; i < pMatrix_from_file->cols; i++) {
                fscanf(file, "%le", &pMatrix_from_file->matr_data[i][j]);
            }
        }
        fclose(file);
        return pMatrix_from_file;
    } else {
        puts("not access");
        return NULL;
        }
}

Matrix* create_matrix(size_t rows, size_t cols) {
    if (rows&&cols) {
        Matrix * pMatrix = NULL;
        pMatrix = malloc(sizeof(Matrix));
        pMatrix->matr_data = malloc(sizeof(*(pMatrix->matr_data))*cols);
        for (size_t i = 0; i < cols; i++) {
            (pMatrix->matr_data)[i] = malloc(sizeof(**(pMatrix->matr_data))*rows);
        }
        return pMatrix;
    } else {
        return NULL;
    }
}

void free_matrix(Matrix* matrix) {
    if (matrix) {
        for (size_t i = 0; i < matrix->cols; i++) {
            free(matrix->matr_data[i]);
        }
        free(matrix->matr_data);
        free(matrix);
    } else { }
}

// Basic operations
int get_rows(const Matrix* matrix, size_t* rows) {
    if (matrix&&rows) {
        *rows = matrix->rows;
        return 0;
    } else {
    return 1;
    }
}

int get_cols(const Matrix* matrix, size_t* cols) {
    if (matrix&&cols) {
        *cols = matrix->cols;
    return 0;
    } else {
        return 1;
    }
}

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    if (matrix&&row&&col&&val) {
        *val = matrix->matr_data[row][col];
        return 0;
    } else {
        return 1;
    }
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (matrix&&row&&col&&val) {
        matrix->matr_data[row][col] = val;
        return 0;
    } else {
        return 1;
    }
}


// Math operations
Matrix* mul_scalar(const Matrix* matrix, double val) {
    if (matrix&&val) {
        Matrix* pMatrix_mul_scalar = create_matrix(matrix->rows, matrix->cols);
            for (size_t j = 0; j < pMatrix_mul_scalar->rows; j++) {
                for (size_t i = 0; i < pMatrix_mul_scalar->cols; i++) {
                    (pMatrix_mul_scalar->matr_data[i][j]) = val* matrix->matr_data[i][j];
                }
            }
        return pMatrix_mul_scalar;
    } else {
        return NULL;
    }
}

Matrix* transp(const Matrix* matrix) {
    if (matrix) {
        Matrix * pMatrix_transp = create_matrix(matrix->rows, matrix->cols);
        for (size_t j = 0; j < pMatrix_transp->rows; j++) {
            for (size_t i = 0; i < pMatrix_transp->cols; i++) {
                (pMatrix_transp->matr_data[i][j]) = matrix->matr_data[j][i];
            }
        }
        return pMatrix_transp;
    } else {
        return NULL;
    }
}

Matrix* sum(const Matrix* l, const Matrix* r) {
    if ((l&&r)&&((l->rows == r->rows)&&(l->cols == r->cols))) {
        Matrix * pMatrix_sum = create_matrix(l->rows, l->cols);
        for (size_t j = 0; j < pMatrix_sum->rows; j++) {
            for (size_t i = 0; i < pMatrix_sum->cols; i++) {
                (pMatrix_sum->matr_data[i][j]) = l->matr_data[i][j] + r->matr_data[i][j];
            }
        }
        return pMatrix_sum;
    } else {
        return NULL;
    }
}

Matrix* sub(const Matrix* l, const Matrix* r) {
    if ((l&&r)&&((l->rows == r->rows)&&(l->cols == r->cols))) {
        Matrix * pMatrix_sum = create_matrix(l->rows, l->cols);
        for (size_t j = 0; j < pMatrix_sum->rows; j++) {
            for (size_t i = 0; i < pMatrix_sum->cols; i++) {
                (pMatrix_sum->matr_data[i][j]) = l->matr_data[i][j] - r->matr_data[i][j];
            }
        }
        return pMatrix_sum;
    } else {
        return NULL;
    }
}

Matrix* mul(const Matrix* l, const Matrix* r) {
    if ((l&&r)&&(l->rows == r->cols)) {
        Matrix* Temp_matr = create_matrix(l->rows, r->cols);
        for (size_t j = 0; j < l->rows; j++) {
            for (size_t i = 0; i < r->cols; i++) {
                Temp_matr->matr_data[i][j] = 0;
                for (size_t k = 0; k < l->cols; k++) {
                    Temp_matr->matr_data[i][j] += l->matr_data[i][k] * r->matr_data[k][j];
                }
            }
        }
        return Temp_matr;
    } else {
        return NULL;
    }
}

// Extra operations
int det(const Matrix* matrix, double* val) {
    if (matrix&&val)
    return 0;
    return 0;
}

Matrix* adj(const Matrix* matrix) {
    if (matrix)
    return NULL;
    return NULL;
}

Matrix* inv(const Matrix* matrix) {
    if (matrix)
    return NULL;
    return NULL;
}
