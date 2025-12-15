#include <stdio.h>
int main(void) {
  unsigned short v = 0x1234;

  FILE *fp = fopen("ngakak.bin", "wb");

  fwrite(&v, sizeof v, 1, fp);
}
