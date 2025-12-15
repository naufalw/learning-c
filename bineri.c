#include <stdio.h>

int main(void) {
  FILE *fp;

  unsigned char bytes[6] = {'K', 'a', 't', 'y', 'a', 2};

  fp = fopen("output.bin", "wb");

  fwrite(bytes, sizeof(char), sizeof(bytes), fp);
}
