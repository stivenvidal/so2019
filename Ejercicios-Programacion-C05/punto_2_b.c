#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

long int variable;
long int valor;

int main(int argc, char *argv[]) {
    int fd = open("texto1.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    assert(fd >= 0);
    char cero[5] = "0";
    int rc = write(fd, cero, 1);
    assert(rc == 1);
    close (fd);

    printf("Numero de veces que desea modificar la variable: ");
    scanf("%ld",&valor);

    char buffer[(valor/2)];
    sprintf(buffer,"%ld",valor);
    char numero [strlen(buffer)];

    pid_t pid;
    pid = fork();

    if (pid > 0){

      int i;
      for(i=0; i<valor; i++){

        int leer = open("texto1.txt", O_RDONLY);
	lseek (leer,0,SEEK_SET);
        read (leer, numero, (strlen(buffer)));
	close (leer);

	variable = atoi(numero) + 1;

	fd = open("texto1.txt", O_WRONLY| O_TRUNC);
        lseek (fd, 0, SEEK_SET);
	sprintf (buffer, "%ld",variable);
        rc = write(fd, buffer, strlen(buffer));
        assert(rc == (strlen(buffer)));
	close (fd);

      }

    }else if(pid == 0){

      int i;
      for(i=0; i<valor; i++){

        int leer = open("texto1.txt", O_RDONLY);
        lseek (leer,0,SEEK_SET);
        read (leer, numero, (strlen(buffer)));
        close (leer);

        variable = atoi(numero) + 1;

        fd = open("texto1.txt", O_WRONLY| O_TRUNC);
        lseek (fd, 0, SEEK_SET);
        sprintf (buffer, "%ld",variable);
        rc = write(fd, buffer, strlen(buffer));
        assert(rc == (strlen(buffer)));
        close (fd);

      }


    }else{
       printf("Error al crear el fork");

    }

    return 0;
}

