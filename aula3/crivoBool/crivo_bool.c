#include <stdlib.h>
#include <stdio.h>
#include "crivo_bool.h"


bool *crivoInit(int n) {
  bool *array = malloc((n-1) * sizeof(bool));

  for(int i=0; i<n-2; i++) {
    array[i]= true;
  }

  return array;
}

void marcaPrimos(bool *array, int n) {
  for(int i=2; i <= n/2;i++) {
    if(array[i] == true) {
      for(int j=2;(j*i) <=n ; j++) {
        array[j*i-2] = false;
      }
    }
  }
}

void printaPrimos(bool *array, int n){
  for(int i=0;i<n-2;i++) {
    if(array[i] == true) { 
      printf("%i\n",i-2);
    }
  }
}