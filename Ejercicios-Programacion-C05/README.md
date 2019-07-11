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

Cuando se corre el programa [punto_3.c](punto_3.c), se evidencia que se logró llevar a cabo el requerimiento, para lograr esto se creó un fichero llamado [autorización.txt](autorización.txt) con un valor inicial de 0, este fichero es leído constantemente por el padre que no puede escribir en pantalla sino hasta que el hijo  sobrescriba en [autorización.txt](autorización.txt) un 1.

## punto 4:

Exec se utiliza para correr un programa en el hijo distinto al que se le programa por defecto cuando se crea el fork, en este caso se usó para hacer una llamada al sistema (ls), esto lo podemos evidenciar al correr el programa  [punto_44c](punto_4.c). lo que diferencia estas variantes de exec son los argumentos que se le ingresan, por ejemplo la dirección del programa que se quiere ejecutar en el hijo.

## Punto 5:

* Al correr el programa [punto_5.c](punto_5.c) observamos que primero se 
ejecutan todas las instrucciones del proceso hijo, mientras que el proceso
padre espera que el hijo termine. 
 
* Ejecutando el programa [punto_5_b.c](punto_5_b.c) el proceso hijo
nunca ejecuta sus instrucciones, ya que el no tiene proceso un hijo para espera

## Punto 6:

Al correr el programa [punto_6.c](punto_6.c), el programa sigue imprimiendo
lo mismo que en el punto [punto_5.c](punto_5.c), pero resulta mas favorable 
utilizar el waitpid en los casos donde se tenga mas de un proceso hijo y se necesite
recibir mas informacion sobre su ejecucion(como saber si se ejecuto correctamente un hijo o o se interrumpio su proceso).

## Punto 7:

Ejecutando el programa [punto_7.c](punto_7.c) podemos observar que el proceso hijo
no puede imprimir nada por pantalla, pero termina correctamente; Esto devido a que
se le cerro la salida estandar.


