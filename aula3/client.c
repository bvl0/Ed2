#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

int main() {
  int n;
  scanf("%i",&n);
  int *array = crivoInit(n);

  marcaPrimos(array,n);
  // printaPrimos(array,n);
  free(array);
}