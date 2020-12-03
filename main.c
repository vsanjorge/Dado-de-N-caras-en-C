#include <stdio.h>
#include <stdlib.h>

void clean_stdin(void) // source: https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(void) {
  int dado = 0;
  for (;;) {
    printf("Por favor introduce un número de caras para el dado (0 para salir): ");
    if (scanf("%d", &dado) != 1) {
      printf("EL VALOR INTRODUCIDO DEBE SER UN NÚMERO\n");
      clean_stdin(); // IMPORTANTÍSIMO
    } else if (dado == 0) {
      printf("Saliendo del programa...\n");
      break;
    } else {
      printf("El resultado de la tirada fue: %d\n", rand()%dado+1);
    }
  }
}