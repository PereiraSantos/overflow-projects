#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct {
    char buffer[64];
    volatile int changeme;
} locals;

int main(int argc, char **argv) {
  char *ptr;

  ptr = getenv("ExploitEducation");
  if (ptr == NULL) {
    errx(1, "por favor defina a variável de ambiente ExploitEducation");
  }

  locals.changeme = 0;
  strcpy(locals.buffer, ptr);

  if (locals.changeme == 0x0d0a090a) {
    puts("Muito bem, você definiu com sucesso o changeme para o valor correto");
  } else {
    printf("Quase! changeme está atualmente 0x%08x, nós queremos 0x0d0a090a\n",
        locals.changeme);
  }

  exit(0);
}
