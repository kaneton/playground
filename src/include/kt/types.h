#ifndef KT_TYPES_H_
# define KT_TYPES_H_

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/

# define NULLPTR                                \
  ((void*) 0U)

/*
 * Assert a condition is true at compile-time.
 * Otherwise generate a compile-time error.
 */
# define KT_STATIC_ASSERT(_COND_)               \
  KT_STATIC_ASSERT_(_COND_, __LINE__)
# define KT_STATIC_ASSERT_(_COND_, _LINE_)      \
  KT_STATIC_ASSERT__(_COND_, _LINE_)
# define KT_STATIC_ASSERT__(_COND_, _LINE_)                     \
  __attribute__ ((unused))                                      \
  typedef char static_assertion_l##_LINE_[(!!(_COND_)) * 2 - 1]

/*----------------------------------------------------------------------------*/
/* Type Definitions                                                           */
/*----------------------------------------------------------------------------*/

typedef signed char             t_int8;
typedef signed short int        t_int16;
typedef signed long int         t_int32;
typedef signed long long int    t_int64;

typedef unsigned char           t_uint8;
typedef unsigned short int      t_uint16;
typedef unsigned int            t_uint32;
typedef unsigned long long int  t_uint64;

typedef float                   t_float32;
typedef double                  t_float64;

typedef unsigned long int       t_word;
typedef t_word                  t_addr;
typedef t_word                  t_size;

typedef enum
{
  E_FALSE = 0,
  E_TRUE  = 1
}                               t_bool;

/*----------------------------------------------------------------------------*/
/* Predicates                                                                 */
/*----------------------------------------------------------------------------*/

KT_STATIC_ASSERT(sizeof (t_int8) == 8 / 8);
KT_STATIC_ASSERT(sizeof (t_int16) == 16 / 8);
KT_STATIC_ASSERT(sizeof (t_int32) == 32 / 8);
KT_STATIC_ASSERT(sizeof (t_int64) == 64 / 8);
KT_STATIC_ASSERT(sizeof (t_uint8) == 8 / 8);
KT_STATIC_ASSERT(sizeof (t_uint16) == 16 / 8);
KT_STATIC_ASSERT(sizeof (t_uint32) == 32 / 8);
KT_STATIC_ASSERT(sizeof (t_uint64) == 64 / 8);
KT_STATIC_ASSERT(sizeof (t_float32) == 32 / 8);
KT_STATIC_ASSERT(sizeof (t_float64) == 64 / 8);
KT_STATIC_ASSERT(sizeof (void*) == sizeof (t_addr));
KT_STATIC_ASSERT(sizeof (void*) == sizeof (t_size));

#endif /* !KT_TYPES_H_ */
