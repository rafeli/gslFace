#ifndef _GSLFACE_HPP
#define _GSLFACE_HPP

#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

// VECTOR 
typedef gsl_vector momoVector_;
typedef gsl_vector_view momoVector_view;
typedef gsl_vector_const_view momoVector_const_view;

momoVector_ *   momo_vector_alloc     (long unsigned int);
void            momo_vector_free      (momoVector_ *);
double          momo_vector_get       (momoVector_ *, long unsigned int);
momoVector_view momo_vector_subvector (momoVector_ *, size_t, size_t);
momoVector_const_view momo_vector_const_subvector (const momoVector_ *, size_t, size_t);
int             momo_vector_sub       (momoVector_*, const momoVector_*);
int             momo_vector_add       (momoVector_*, const momoVector_*);
int             momo_vector_scale     (momoVector_*, const double);

// MATRIX
typedef gsl_matrix momoMatrix_;
momoMatrix_ *   momo_matrix_alloc     (long unsigned int, long unsigned int);
void            momo_matrix_free      (momoMatrix_ *);
momoVector_view momo_matrix_row       (momoMatrix_ *, size_t i);
double          momo_matrix_get       (momoMatrix_ *, size_t, size_t);
void            momo_matrix_set       (momoMatrix_ *, size_t, size_t, double);
void            momo_matrix_set_zero  (momoMatrix_ *);
int             momo_matrix_memcpy    (momoMatrix_ *, momoMatrix_*);
int             momo_matrix_scale(momoMatrix_ *, const double ) ;

// BLAS
double          momo_blas_dnrm2       (const momoVector_ *);
int             momo_blas_ddot        (const momoVector_ *, const momoVector_*, double * );
int             momo_blas_dgemv       (CBLAS_TRANSPOSE_t , double , const momoMatrix_* , const momoVector_* , double , momoVector_* );
int             momo_blas_dgemm       (CBLAS_TRANSPOSE_t , CBLAS_TRANSPOSE_t, double , const momoMatrix_* , const momoMatrix_* , double , momoMatrix_* );

#endif 
