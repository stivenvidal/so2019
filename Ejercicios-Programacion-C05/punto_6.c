#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  pid_t pid;
  int status;
  char *argumentos[3] = {"ls", "-l", NULL};
  pid = fork();
  if (pid == -1){
  printf ("fallo al crear el fork\n");

  }else if (pid == 0){
  execv ("/bin/ls",argumentos);

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
