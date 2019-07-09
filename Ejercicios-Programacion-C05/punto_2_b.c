
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
    close(fd);


    printf("Numero de veces que desea modificar la variable: ");
    scanf("%ld",&valor);
    int rc;

    pid_t pid;

    pid = fork();

    char buffer[40];

    if (pid > 0){

      int i;
      for(i=0; i<valor; i++){
//	sprintf (buffer, "%ld\n",variable);

	char numero [valor];
        int fd = open("texto1.txt", O_RDONLY);
	lseek (fd,0,SEEK_SET);
        read (fd, numero, valor);
	close (fd);
	int variable = numero

	int fd = open("texto1.txt", O_WRONLY| O_TRUNC);
        lseek (fd, 0, SEEK_END);

        int rc = write(fd, buffer, strlen(buffer));
        assert(rc == (strlen(buffer)));
	close (fd);

      }

    }else if(pid == 0){

      int i;
      for(i=0; i<valor; i++){
	variable++;
        sprintf (buffer, "%ld\n",variable);

        int fd = open("texto1.txt", O_WRONLY);
        lseek (fd, 0, SEEK_END);

        int rc = write(fd, buffer, strlen(buffer));
        assert(rc == (strlen(buffer)));
        close (fd);

      }

    }else{
      printf("Error al crear el fork");

    }

    fsync(fd);
//    close(fd);
    return 0;
}

