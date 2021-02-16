#include<stdio.h>
#include<stdlib.h>

#include "crivo.h"

int8_t *crivoInit(int n){
  int8_t *array;
  if ((n-1)%8 == 0){
    array = malloc(((n-1)/8) * sizeof(int8_t));
  }
  else {
    array = malloc(((n-1)/8 +1) * sizeof(int8_t));
  }

  for(int i=0;i<=n-2;i++){
    setBit(array,i);
  }

  return array;
}

void marcaPrimos(int8_t *array, int n){
  for(int i=2; i <= n/2;i++) {
    if(isBitSet(array,i)) {
      for(int j=2;(j*i) <=n ; j++) {
        clearBit(array,j*i-2);
      }
    }
  }
}

void printaPrimos(int8_t *array, int n){
  for(int i=0;i<=n-2;i++) {
    if(isBitSet(array,i)) { 
      printf("%i\n",i+2);
    }
  }
}