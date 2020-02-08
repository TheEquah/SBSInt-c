// Author (Created): Roger "Equah" Hürzeler
// Author (Modified): Roger "Equah" Hürzeler
// Date (Modified): 12020.02.08 HE
// License: apache-2.0

#include "equah/sbsint.h"

// [>] Stream
// [i] Buffer which simulates a stream of data.
char stream[100];

// [>] Stream Read
// [i] Reads a single byte from the "stream".
unsigned char stream_read() {
	static size_t pos = 0;
	unsigned char c = stream[pos];
	pos++;
	printf("0x%x; ", c);
	return c;
}

// [>] Stream Write
// [i] writes a single byte to the "stream".
void stream_write(unsigned char c) {
	static size_t pos = 0;
	stream[pos] = c;
	printf("0x%x; ", (unsigned char) c);
	pos++;
}

// [>] Main
int main() {
  
  // [i] Declare convert variables.
  int start_int = 420;
  size_t sbsint_len = 10;
  int end_int;
  
  // [i] Convert integer.
	printf("\nStart integer: %i", start_int);
  printf("\nSBSInt required lengt: %li", equah_sbsint__required_bytes(start_int));
	printf("\nWriting: ");
	size_t its = equah_sbsint__int_to_sbytes(start_int, &stream_write);
	printf("(Written amount: %li)\nReading: ", its);
  size_t sti = equah_sbsint__sbytes_to_int(&stream_read, &end_int);
  printf("(Read amount: %li)\nResult integer: %i\n", sti, end_int);
	
  return 0;
}
