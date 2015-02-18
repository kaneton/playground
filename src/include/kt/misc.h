/*
 * Misc Utilities.
 */

#ifndef KT_MISC_H_
# define KT_MISC_H_

# include "kt/types.h"

/*----------------------------------------------------------------------------*/
/* Macro Definitions                                                          */
/*----------------------------------------------------------------------------*/

/*!
 * Stringify a value.
 * \param _M_ value to stringify
 */
# define KT_MISC_STRINGIFY(_M_)                 \
  KT_MISC_STRINGIFY_(_M_)
# define KT_MISC_STRINGIFY_(_M_)                \
  #_M_

/*!
 * Align an address with an alignment mask.
 * \param _ADDR_  value to align
 * \param _ALIGN_ alignement mask, ie the alignement size - 1 (e.g. 16KB - 1)
 */
# define KT_MISC_ALIGN(_ADDR_, _ALIGN_)         \
  (((_ADDR_) + (_ALIGN_)) & ~(_ALIGN_))

/*!
 * Generate a mask of _N_ bits.
 * Useful to define registers.
 * Rely on the well-defined (standardized) unsigned integer overflow.
 * \param _N_ number of bits set
 * E.g. KT_MISC_MASK(2) = 11
 *      KT_MISC_MASK(3) = 111
 */
# define KT_MISC_MASK(_N_)                      \
  ((1ULL << (_N_)) - 1ULL)

/*!
 * Fully set mask 0b1..1.
 * The largest mask possible to cover every data-types.
 * Useful to define registers, in particular masks.
 * Rely on the well-defined (standardized) unsigned integer overflow.
 */
# define KT_MISC_MASK_FULL      (0ULL - 1ULL)

/*!
 * Left Rotation.
 * \param[in] _L_ _N_'s length - number of bits.
 * \param[in] _N_ number
 * \param[in] _S_ number of bits to rotate.
 * \return _N_ left-rotated of _S_ bits.
 */
# define KT_MISC_ROTL(_L_, _N_, _S_)              \
  (((_N_) << (_S_)) | ((_N_) >> ((_L_) - (_S_))))

/*!
 * Right Rotation.
 * \param[in] _L_ _N_'s length - number of bits.
 * \param[in] _N_ number
 * \param[in] _S_ number of bits to rotate.
 * \return _N_ right-rotated of _S_ bits.
 */
# define KT_MISC_ROTR(_L_, _N_, _S_)              \
  (((_N_) >> (_S_)) | ((_N_) << ((_L_) - (_S_))))

/*!
 * \return 1UL << (log2(_N_ - 1) + 1)
 */
# define KT_MISC_NEXT_POWER_OF_2(_N_)                     \
  ({                                                      \
    DBG_STATIC_ASSERT(sizeof (_N_) >= sizeof(t_uint32));  \
    t_uint8  u_o = (_N_) == 0 ? 1 : 0;                    \
    t_uint32 u_n = (_N_) - 1 + u_o;                       \
    u_n = u_n | (u_n >> 1);                               \
    u_n = u_n | (u_n >> 2);                               \
    u_n = u_n | (u_n >> 4);                               \
    u_n = u_n | (u_n >> 8);                               \
    u_n = u_n | (u_n >> 16);                              \
    u_n + 1;                                              \
  })

#endif /* !KT_MISC_H_ */
