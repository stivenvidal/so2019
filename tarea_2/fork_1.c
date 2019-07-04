#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int variable;

int main(int argc, char** argv) {
  variable = 50;

  pid_t pid;

  pid = fork();

  if (pid != 0){
    printf("padre : %d\n",variable);
  }else{
    printf("Hijo : %d\n",variable);
  }

  return 0;
  return 0;
}
