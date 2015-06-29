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
momoMatrix_*      momo_matrix_alloc(long unsigned int rows, long unsigned int cols) {
                    return gsl_matrix_alloc(rows,cols);
                  }
void              momo_matrix_free(momoMatrix_ *m) { gsl_matrix_free(m); }
momoVector_view   momo_matrix_row(momoMatrix_ *m, size_t i) { return gsl_matrix_row(m,i);}
double            momo_matrix_get(momoMatrix_ *m, size_t i, size_t j) { return gsl_matrix_get(m,i,j);}


// BLAS:
double            momo_blas_dnrm2(const momoVector_ *v) { return gsl_blas_dnrm2(v);}
int               momo_blas_ddot(const momoVector_ *x, const momoVector_ *y, double *r) { return gsl_blas_ddot(x,y,r);}

