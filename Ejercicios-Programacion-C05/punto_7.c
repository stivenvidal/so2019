#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

  int status;
  pid_t pid;
  pid = fork();

  if (pid == -1){
    printf ("fallo al crear el fork\n");

  }else if (pid == 0){
    close(STDOUT_FILENO);

    printf ("hola desde el hijo\n");

  }else{
    waitpid (pid,&status,0);

    if ((WIFEXITED(status)) != 0){
      printf ("Ejecucion normal del hijo\n");
    }else{
      printf("Error en la ejecucion del hijo\n");
    }

    printf("Padre terminado.\n");
  }


return (0);
}
