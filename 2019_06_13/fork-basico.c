#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>                                                           
                                                                               
int main(int argc, char** argv) {                                
  printf ("hola\n"); 
  pid_t pid;                                                                   
                                                                               
  pid = fork();     
  printf ("hola222\n");                                                          
  if (pid != 0) {                                                              
    printf("soy el padre mi id es %d y el de mi hijo es %d\n",getpid(),pid);   
  } else {   
    printf("soy el hijo con id %d y mi variable pid es %d\n",getpid(),pid);       
  }
                                                                               
  return 0;                                                                   
  return 0;                                                                    
}  
