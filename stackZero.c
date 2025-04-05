#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct {
    char buffer[64];
    volatile int changeme;
} locals;

char *gets(char *);

int main(int argc, char **argv) {

  locals.changeme = 0;
  gets(locals.buffer);

  if (locals.changeme != 0) {
    puts("Muito bem, a variável 'changeme' foi alterada!");
  } else {
    puts("Uh oh, 'changeme' ainda não foi alterado. Você gostaria de tentar novamente?");
  }

  exit(0);
}
