// Author (Created): Roger "Equah" Hürzeler
// Author (Modified): Roger "Equah" Hürzeler
// Date (Created): 12019.12.26 HE
// Date (Modified): 12020.02.08 HE
// License: apache-2.0

#include "equah/sbsint.h"

// [>] Bytes To Integer
// [i] Converts a SBSInt char array to an integer.
// [P] {unsigned char *} b => Char array to read SBSInt from.
// [P] {size_t} b_len => Available space to read SBSInt from char rray.
// [P] {equah_sbsint__DEFAULT_INT_TYPE *} i => Integer to store read SBSInt value.
// [R] {size_t} => Amount of bytes read for SBSInt.
size_t equah_sbsint__bytes_to_int(unsigned char *b, size_t b_len, equah_sbsint__DEFAULT_INT_TYPE *i) {
	size_t pos = 1;
	*i = 0;
	
	unsigned char next_byte = b[0];
	while (next_byte == 0xFF) {
		*i += (unsigned char) 0xFF;
		next_byte = b[pos];
		pos++;
	}
	
	*i += (unsigned char) next_byte;
	
	return pos;
}

// [>] Single Bytes To Integer
// [i] Uses given function to read single SBSInt bytes and converts to integer.
// [P] {unsigned char (*fn)()} fn_r => Pointer to function to read single bytes.
// [P] {equah_sbsint__DEFAULT_INT_TYPE *} i => Integer to store read SBSInt value.
// [R] {size_t} => Amount of bytes read for SBSInt.
size_t equah_sbsint__sbytes_to_int(unsigned char (*fn_r)(), equah_sbsint__DEFAULT_INT_TYPE *i) {
	size_t pos = 1;
	*i = 0;
	
	unsigned char next_byte = fn_r();
	while (next_byte == 0xFF) {
		*i += (unsigned char) 0xFF;
		next_byte = fn_r();
		pos++;
	}
	
	*i += (unsigned char) next_byte;
	
	return pos;
}

// [>] Integer To Bytes
// [i] Converts an integer to SBSInt char array.
// [P] {equah_sbsint__DEFAULT_INT_TYPE} i => Integer to convert to SBSInt bytes.
// [P] {unsigned char *} b => Char buffer to write SBSInt.
// [P] {size_t} b_len => Amount of available space in buffer.
// [R] {size_t} => Amount of bytes written for SBSInt.
size_t equah_sbsint__int_to_bytes(equah_sbsint__DEFAULT_INT_TYPE i, unsigned char *b, size_t b_len) {
	size_t size = 0;
	
	while (i >= 0xFF) {
		b[size] = (unsigned char) 0xFF;
		i -= (unsigned char) 0xFF;
		size++;
	}
	
	b[size] = (unsigned char) i;
	size++;
	
	return size;
}

// [>] Integer To Single Bytes
// [i] Uses given function to write single SBSInt bytes from integer.
// [P] {equah_sbsint__DEFAULT_INT_TYPE} i => Integer to convert to SBSInt bytes.
// [P] {void (*fn)(unsigned char)} fn_w => Function to write single byte.
// [R] {size_t} => Amount of bytes written for SBSInt.
size_t equah_sbsint__int_to_sbytes(equah_sbsint__DEFAULT_INT_TYPE i, void (*fn_w)(unsigned char)) {
	size_t size = 0;
	
	while (i >= 0xFF) {
		fn_w((unsigned char) 0xFF);
		i -= (unsigned char) 0xFF;
		size++;
	}
	
	fn_w((unsigned char) i);
	size++;
	
	return size;
}

// [>] Required Bytes
// [i] Calculates the amount of required bytes for a given number.
// [P] {equah_sbsint__DEFAULT_INT_TYPE} i => Integer to get required size of.
// [R] {size_t} => Required array length to store given integer.
size_t equah_sbsint__required_bytes(equah_sbsint__DEFAULT_INT_TYPE i) {
	
	size_t len = (i / (unsigned char) 255) + 1;
	
	return len;
}

