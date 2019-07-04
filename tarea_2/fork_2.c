#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int i;
volatile int variable;
long int valor;

int main(int argc, char** argv) {
  scanf("%ld",&valor);

  pid_t pid;

  pid = fork();

  for (i = 0; i < valor; i++) {
	variable++;
    }

  if (pid != 0){
    printf("padre : %d\n",variable);
  }else{
    printf("Hijo : %d\n",variable);
  }

  return 0;
  return 0;
}
