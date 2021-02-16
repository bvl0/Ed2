#include<stdlib.h>
#include<stdio.h>
#include"bit.h"
void setBit(int8_t *array, int n) {
  array[n / 8] |= 1U << n%8;
}

void clearBit(int8_t *array, int n) {
  array[n / 8] &= ~(1U << n%8);
}

bool isBitSet(int8_t *array, int n) {
  return array[n / 8] >> n%8 & 1U;
}