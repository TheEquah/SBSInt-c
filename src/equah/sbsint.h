// Author (Created): Roger "Equah" Hürzeler
// Author (Modified): Roger "Equah" Hürzeler
// Date (Created): 12019.12.26 HE
// Date (Modified): 12020.01.05 HE
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
size_t equah_sbsint__sbytes_to_int(unsigned char (*)(), equah_sbsint__DEFAULT_INT_TYPE *i);
size_t equah_sbsint__int_to_bytes(equah_sbsint__DEFAULT_INT_TYPE, unsigned char *, size_t);
size_t equah_sbsint__int_to_sbytes(equah_sbsint__DEFAULT_INT_TYPE, void (*)(unsigned char));
size_t equah_sbsint__required_bytes(equah_sbsint__DEFAULT_INT_TYPE);


#endif
