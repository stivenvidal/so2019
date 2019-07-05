#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int variable;

int main(int argc, char** argv) {

  variable = 50;

  pid_t pid;

  pid = fork();

  if (pid != 0){
    printf("Valor de la variabble en el padre :\t%d\n",variable);
  }else{
    printf("Valor de la variable en el hijo :\t%d\n",variable);
  }

  return 0;
}
