// Author (Created): Roger "Equah" Hürzeler
// Date (Created): 12019.12.26 HE
// License: apache-2.0

#include "equah/sbsint.h"

// [>] Main
int main() {
  
  // [i] Declare convert variables.
  int start_int = 420;
  size_t sbsint_len = 10;
  char sbsint[sbsint_len];
  int end_int;
  
  // [i] Convert integer.
  size_t req_len = equah_sbsint__requied_bytes(start_int);
  size_t its = equah_sbsint__int_to_bytes(start_int, sbsint, sbsint_len);
  size_t sti = equah_sbsint__bytes_to_int(sbsint, sbsint_len, &end_int);
  
  // [i] Print result.
  printf("\nRequired byte array size for %i: %li\n\n", start_int, req_len);
  printf("\n%i -> [", start_int);
  size_t pos = 1;
  printf("0x%x", (unsigned char) sbsint[0]);
  while (sbsint_len > pos) {
    printf(", 0x%x", (unsigned char) sbsint[pos]);
    pos++;
  }
  printf("] -> %i\n\n", end_int);
  
  return 0;
}
