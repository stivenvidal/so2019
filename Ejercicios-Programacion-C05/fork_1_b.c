#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


volatile int variable = 0;
long int valor;


int main(int argc, char** argv) {

  printf("Numero de veces que desea modificar la variable: ");
  scanf("%ld",&valor);

  pid_t pid;

  pid = fork();

  int i;
  for (i=0; i<valor; i++){
    variable++;
  }

  if (pid > 0){
    printf("Valor de la variable en el padre:\t%d\n",variable);
  }else{
    printf("Valor de la variable en el hijo:\t%d\n",variable);
  }

return 0;

}
