#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // IMPORTANTE para poder utilizar getpid()

void clean_stdin(void) // UTILIZAR ESTE MÉTODO SI fflush(stdin) DIESE PROBLEMAS! source: https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(void) {
  void srand(unsigned int seed); // IMPORTANTE inicializar para poder generar la semilla
  srand(getpid()); // IMPORTANTE para generar una nueva semilla con cada ejecución del programa
  int dado = 0;
  for (;;) {
    printf("Por favor introduce un número de caras para el dado (0 para salir): ");
    if (scanf("%d", &dado) != 1) {
      printf("EL VALOR INTRODUCIDO DEBE SER UN NÚMERO\n");
      clean_stdin(); // IMPORTANTE para que el bucle funcione como queremos, se puede probar también con fflush(stdin)
    } else if (dado == 0) {
      printf("Saliendo del programa...\n");
      break;
    } else {
      printf("El resultado de la tirada fue: %d\n", rand()%dado+1);
    }
  }
}