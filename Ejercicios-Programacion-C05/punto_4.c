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
  execvp (argumentos[0],argumentos);

  }else{
    while (wait (&status) != pid);
    if (status ==  0){
      printf ("ejecucion normal del hijo\n");
    }else{
      printf("error del hijo\n");

    }

    

  }

return (0);
}
