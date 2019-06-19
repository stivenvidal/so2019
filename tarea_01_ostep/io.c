#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

 FILE *file;
int exists(const char *fname)
{
   
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

void Invertir(char buffer[100])
{
	int i,j;
    int palabra = strlen(buffer)/2;
	char newbuffer;
	for(i=0,j=strlen(buffer)-2;i<palabra;i++,j--){
		newbuffer=buffer[i];
		buffer[i]=buffer[j];
		buffer[j]=newbuffer;
	}
}


int main(int argc, char *argv[]) {

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); //abrir archivo
    assert(fd >= 0); 
    char buffer[100];
    sprintf(buffer, "hola mundo, amo a mi mama, mi mama me mima\n");
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    if(exists(argv[1])){
        file = fopen(argv[1], "r");
        printf("%s\n", buffer);
        fseek(file, -2, SEEK_END);
        Invertir(buffer);
        printf("%s", buffer);
    }
    fsync(fd);
    close(fd);
    return 0;
}


