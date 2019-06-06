#include <stdio.h>

int main (int argc, char** argv) {                                               
  int x1, x2, x3;                                                               
                                                                                
  x1 = sizeof(char);                                                            
  x2 = sizeof(int);                                                             
  x3 = sizeof(float); 

  printf ("%d %d %d",x1,x2,x3);
}
