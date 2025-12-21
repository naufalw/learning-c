#include <signal.h>
#include <stdio.h>
int main(void) {
  char s[1024];

  signal(SIGINT, SIG_IGN);

  printf("Hit ^c");

  fgets(s, sizeof s, stdin);
}
