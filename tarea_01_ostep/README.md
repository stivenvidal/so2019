mem:
- Se ejecutaron todas las instrucciones y comandos necesarios indicados en el documento de la tarea
  para acceder al modo super usuario, donde se modiicó la configuracion de memoria, que hizo posible
  la ejecución del programa dos veces de manera concurrente accediendo a la misma region de memoria
  sin afectar la ejecución y el resultado de los programas.

threads:
- Se procedió a la creación de un nuevo archivo de extensión punto hache (mycommon.h), donde se
  alojaron las funciones necesarias generar una pausa temporal a uno de los hilos mientras
  el otro modificaba la variable (generar_puerta(), abrir_puerta(), cerrar_puerta(), destruir_puerta())
                        
- Se modificó el archivo threads.c inluyendo a "mycommon.h", con el fin de añadir las funciones 
  incluidas en este, para condicionar el momento el que cada hilo accede a modificar la variable.

io:
- Se procede a leer el archivo de texto que contiene la frase, se ubica el puntero al final de la 
  frase con la ayuda de la funcion "fseek()"; y con la llamada a la función "invertir()" que contiene
  un ciclo "for()" que retorna la frase invertida caracter por caracter y la almacena en una cadena
  llamada "buffer[]", variable que finalmente se imprime.
