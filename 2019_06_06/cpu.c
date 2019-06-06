#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{ 
    int i;
    printf("Num. de argumentos %d\n",argc);
    for (i = 0; i < argc; i++)
	printf ("[%d] %s\n",i,argv[i]);

    if (argc != 2) {
	fprintf(stderr, "usage: cpu <string>\n");
	exit(1);
    }
    char *str = argv[1];

    while (1) {
	printf("%s\n", str);
	Spin(1);
    }
    return 0;
}

