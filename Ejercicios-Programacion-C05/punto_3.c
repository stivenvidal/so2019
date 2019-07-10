#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd = open("autorizacion.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    assert(fd >= 0);
    char cero[5]= "0";
    int rc = write(fd,cero,1);
    assert (rc == 1);
    close (fd);

    pid_t pid;

    pid = fork();

///    char buffer[40];

    if (pid > 0){

      int si = 0;
      while (si != 1){
        int leer = open ("autorizacion.txt", O_RDONLY);
        lseek (fd,0,SEEK_SET);
        char senal[2];
        read (fd, senal,2);
        close (leer);
        si = atoi(senal);

      }

      printf ("Adios desde el padre.\n");
//    printf ("%s",buffer);
//    int tam = strlen(buffer);
  //  printf ("%d",tam);

    }else if(pid == 0){
 
      printf("Hola desde el hijo\n");

      fd = open ("autorizacion.txt",O_WRONLY| O_TRUNC);
      char uno[2]="1";
      rc = write (fd,uno,strlen(uno));
      assert (rc == strlen(uno));
      close (fd);

    }else{
      printf("Error al crear el fork");
    }
    
    return 0;
}

