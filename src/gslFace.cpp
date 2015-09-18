#include "gslFace.hpp"

// Vector Allocation, init and access
momoVector_*      momo_vector_alloc(long unsigned int x) { return gsl_vector_alloc(x);}

void              momo_vector_free(momoVector_ * v) { gsl_vector_free(v);}

double            momo_vector_get(momoVector_ *v, long unsigned int i) { return gsl_vector_get(v,i); }
momoVector_view   momo_vector_subvector(momoVector_ *v, size_t offset, size_t n) {
                    return gsl_vector_subvector(v,offset,n);
                  }
momoVector_const_view   momo_vector_const_subvector(const momoVector_ *v, size_t offset, size_t n) {
                    return gsl_vector_const_subvector(v,offset,n);
                  }

// Vector Operations
int  momo_vector_sub(momoVector_*a, const momoVector_*b) {return gsl_vector_sub(a,b);}
int  momo_vector_add(momoVector_*a, const momoVector_*b) {return gsl_vector_add(a,b);}
int  momo_vector_scale(momoVector_*a, const double b) {return gsl_vector_scale(a,b);}

// Matrix functins
momoMatrix_*      momo_matrix_alloc(long unsigned int rows, long unsigned int cols) {return gsl_matrix_alloc(rows,cols);}
void              momo_matrix_free(momoMatrix_ *m) { gsl_matrix_free(m); }
momoVector_view   momo_matrix_row(momoMatrix_ *m, size_t i) { return gsl_matrix_row(m,i);}
double            momo_matrix_get(momoMatrix_ *m, size_t i, size_t j) { return gsl_matrix_get(m,i,j);}
void              momo_matrix_set(momoMatrix_ *m, size_t i, size_t j, double x) {return gsl_matrix_set(m,i,j,x);}
void              momo_matrix_set_zero(momoMatrix_ *m) {return gsl_matrix_set_zero(m);}
int               momo_matrix_memcpy(momoMatrix_ *d, momoMatrix_ *s) {return gsl_matrix_memcpy(d,s);}
int               momo_matrix_scale(momoMatrix_ *a, const double x) { return gsl_matrix_scale(a,x);}


// BLAS:
double            momo_blas_dnrm2(const momoVector_ *v) { return gsl_blas_dnrm2(v);}
int               momo_blas_ddot(const momoVector_ *x, const momoVector_ *y, double *r) { return gsl_blas_ddot(x,y,r);}
int               momo_blas_dgemv(CBLAS_TRANSPOSE_t t, double alpha, const momoMatrix_* A, const momoVector_* v, double beta, momoVector_* result) { return gsl_blas_dgemv(t, alpha, A, v, beta, result);}
int               momo_blas_dgemm(CBLAS_TRANSPOSE_t tA, CBLAS_TRANSPOSE_t tB, double alpha, const momoMatrix_* A, const momoMatrix_* B, double beta, momoMatrix_* result) { return gsl_blas_dgemm(tA, tB, alpha, A, B, beta, result);}
int               momo_blas_dger(double alpha, const momoVector_* x, const momoVector_* y, momoMatrix_* A){return gsl_blas_dger(alpha, x,y,A);}
 

