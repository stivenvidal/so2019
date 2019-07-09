#Capítulo 5:
##Punto 1:

Al correr el programa [fork_1_a.c](fork_1_a.c) podemos observar que el valor de la.
variable en el proceso hijo tiene el mismo valor que el proceso padre, esto es por que.
el proceso hijo copia todas las variables del proceso padre, pero estas no son.
compartidas; Por esto mismo podemos ver que al correr el programa [fork_1_b.c](fork_1_b.c),.
y modoficar la variable al mismo tiempo en el padre y en el hijo cuantas veces queramos,.
el valor de la variable no se verá afectado, al contrario de lo que sucede en los Threads.

##Punto 2:


