#include <stdio.h>
#include <stdlib.h>
#include "crivo_bool.h"

int main() {
  int n;
  scanf("%i",&n);
  bool *array = crivoInit(n);

  marcaPrimos(array,n);
  //printaPrimos(array,n);
  free(array);
}