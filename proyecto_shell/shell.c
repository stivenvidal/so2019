#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
  char comando[256];
  pid_t pid;
  while (1) {
    printf("> ");
    scanf ("%s",comando);
    if (strncmp(comando,"exit",4) == 0) {
      break;
    }
    pid = fork();
    if (pid != 0) {
      wait(NULL);
    } else {
      if (strcmp(comando,"dir") == 0) {
        // listar el contenido de archivos en ese directorio
        printf("debo listar archivos\n");

	char* argumentos [3] = {"ls","-l",NULL};
        execvp("ls",argumentos);

      } else if (strcmp(comando, "clear") == 0) {
        // limpiar pantalla
        printf("debo limpiar pantalla\n");

	char* argumentos [2] = {"clear",NULL};
	execvp("clear",argumentos);

      } else { 
        //strtok
        //revisar alguna variante de exec 
        //exec(comando);
      }
    }
  }
  exit(0);
}
