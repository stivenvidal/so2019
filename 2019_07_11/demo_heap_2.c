#include <stdio.h>
#include <stdlib.h>                                                                              
                                                                                                 
void demo(char *x,char* z){                                                                              
 *x = 'b';               
 *z = 'c';                                                                        
}                                                                                                
                                                                                                 
int main(int argc, char** argv) {                                                                
  char z = 'a';                                                                                  
                                                                                                 
  demo(&z,&z);                                                                                      
  printf ("%c\n",z);                                                                              
                                                                                                 
  return 0;                                                                                      
} 
