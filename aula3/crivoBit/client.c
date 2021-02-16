#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

int main() {
  int n;
  scanf("%i",&n);
  int8_t *array = crivoInit(n);

  marcaPrimos(array,n);
  //printaPrimos(array,n);
  free(array);
}