#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int dado = 0;

  for (;;) {
    //system("clear");
    printf("Por favor introduce un número de caras para el dado (0 para salir): ");
    //scanf("%d", &dado);
    if (scanf("%d", &dado) != 1) {
      printf("EL VALOR INTRODUCIDO DEBE SER UN NÚMERO\n");
      break;
    } else if (dado == 0) {
      printf("Saliendo del programa...\n");
      break;
    } else {
      printf("El resultado de la tirada fue: %d\n", rand()%dado+1);
    }
  }
}