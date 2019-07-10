
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int fd = open("texto.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    assert(fd >= 0);

    pid_t pid;

    pid = fork();

    char buffer[40];

    if (pid > 0){
      sprintf(buffer, "Escribiendo desde el padre\n");


    }else if(pid == 0){
      sprintf(buffer, "Escribiendo desde el hijo\n");


    }else{
      printf("Error al crear el fork");

    }

    int rc = write(fd, buffer, strlen(buffer));
    assert(rc == (strlen(buffer)));
    fsync(fd);
    close(fd);
    return 0;
}
