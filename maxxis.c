#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  printf("Signed Char:   %d to %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("Unsigned Char: 0 to %u\n", UCHAR_MAX);

  // Short
  printf("Signed Short:  %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("Unsigned Short: 0 to %u\n", USHRT_MAX);

  // Int
  printf("Signed Int:    %d to %d\n", INT_MIN, INT_MAX);
  printf("Unsigned Int:  0 to %u\n", UINT_MAX);

  // Long
  printf("Signed Long:   %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("Unsigned Long: 0 to %lu\n", ULONG_MAX);

  return 0;
}
