#ifndef _GSLFACE_HPP
#define _GSLFACE_HPP

#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

// VECTOR & MATRIX
typedef gsl_vector momoVector_;
typedef gsl_vector_view momoVector_view;
typedef gsl_vector_const_view momoVector_const_view;
typedef gsl_matrix momoMatrix_;

momoVector_ *   momo_vector_alloc     (long unsigned int);
void            momo_vector_free      (momoVector_ *);
double          momo_vector_get       (momoVector_ *, long unsigned int);
momoVector_view momo_vector_subvector (momoVector_ *, size_t, size_t);
momoVector_const_view momo_vector_const_subvector (const momoVector_ *, size_t, size_t);

momoMatrix_ *   momo_matrix_alloc     (long unsigned int, long unsigned int);
void            momo_matrix_free      (momoMatrix_ *);
momoVector_view momo_matrix_row       (momoMatrix_ *, size_t i);
double          momo_matrix_get       (momoMatrix_ *, size_t, size_t);

// BLAS
double          momo_blas_dnrm2       (const momoVector_ *);


#endif 
