// deve fallar al compilar  por que *x no es una variable global (esta dentro de main)
#include <stdio.h>                                                                               
#include <stdlib.h>                                                                              
                                                                                                 
int *p;                                                                                          
                                                                                                 
int suma(int a) {                                                                                
  return a + *p;                                                                                 
}                                                                                                
                                                                                                 
int bad_suma(int a) {                                                                            
  return a + *x;                                                                                 
}                                                                                                
                                                                                                 
int main(int argc, char** argv) {                                                                
  int *x;                                                                                        
  x = (int*) malloc(sizeof(int));                 //                                               
  *x = 10;                                          //asigno memoria                                             
  p = (int*) malloc(sizeof(int));                                                                
  *p = 20;                                                                                       
  printf("La suma es: %d\n",suma(10));                                                          
  printf("La suma mal es: %d\n",bad_suma(10));     

  free(x); free(p); //libero memoria
                                                                                                 
  return 0;                                                                                      
} 
