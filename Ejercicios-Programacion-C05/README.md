# Capítulo 5.
## Punto 1:

Al correr el programa [fork_1_a.c](fork_1_a.c) podemos observar que el valor de la
variable en el proceso hijo tiene el mismo valor que el proceso padre, esto es por que
el proceso hijo copia todas las variables del proceso padre, pero estas no son
compartidas; Por esto mismo podemos ver que al correr el programa [fork_1_b.c](fork_1_b.c),
y modoficar la variable al mismo tiempo en el padre y en el hijo cuantas veces queramos,
el valor de la variable no se verá afectado, al contrario de lo que sucede en los Threads.

## Punto 2:

* Al correr el programa [punto_2_a.c](punto_2_a.c) podemos observar que ambos programas 
acceden al mismo fichero llamado 'texto.txt' y lo modifican cada uno con una frase diferente, 
esto se puede comprobar abriendo el fichero.

* Cuando corremos el programa [punto_2_b.c](punto_2_b.c) ambos procesos acceden al fichero
'texto1.txt' y lo modifican concurrentemente; Esto causa que se pierdan ciertos datos,(como sucedia
con los threads) haciendo que no se guarde en el fichero el valor que deveria (el doble que el numero que ingrese).

## Punto 3:


