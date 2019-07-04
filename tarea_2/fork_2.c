#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int i;
volatile int variable = 0;
long int valor;


int main(int argc, char** argv) {

  printf("Numero de veces que desea modificar la variable: ");
  scanf("%ld",&valor);

  pid_t pid;

  pid = fork();

  for (i=0; i<valor; i++){
    variable++;
  }

  if (pid != 0){
    printf("padre :\t%d\n",variable);
  }else{
    printf("Hijo :\t%d\n",variable);
  }

  return 0;
  //return 0;
}
