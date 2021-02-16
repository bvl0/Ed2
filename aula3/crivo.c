#include <stdlib.h>
#include <stdio.h>
#include "crivo.h"

int *crivoInit(int n) {
  int *array = malloc((n - 1)* sizeof(int));
  
  for(int i=0; i <= n-2; i++) {
    array[i] = 1;
  }

  return array;
}

void marcaPrimos(int *array, int n) {
  for(int i=2; i <= n/2;i++) {
    if(array[i] == 1) {
      for(int j=2;(j*i) <=n ; j++) {
        array[j*i-2] = 0;
      }
    }
  }
}

void printaPrimos(int *array, int n){
  for(int i=0;i<=n-2;i++) {
    if(array[i] == 1) { 
      printf("%i\n",i+2);
    }
  }
}