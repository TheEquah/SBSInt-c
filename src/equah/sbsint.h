// Author (Created): Roger "Equah" Hürzeler
// Date (Created): 12019.12.26 HE
// License: apache-2.0

#ifndef equah_sbsint__HEADER
#define equah_sbsint__HEADER

#include <stddef.h>
#include <stdio.h>

// [>] Default Integer Type
// [i] Default type used when working with integers.
#define equah_sbsint__DEFAULT_INT_TYPE unsigned int

// [i] Function declarations.
size_t equah_sbsint__bytes_to_int(unsigned char *, size_t, equah_sbsint__DEFAULT_INT_TYPE *);
size_t equah_sbsint__int_to_bytes(equah_sbsint__DEFAULT_INT_TYPE, unsigned char *, size_t);
size_t equah_sbsint__requied_bytes(equah_sbsint__DEFAULT_INT_TYPE);


#endif
