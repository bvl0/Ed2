#include "insertSort.h"

void sort(Item *a, int lo, int hi){
  int j, pivo;

  for(int i= lo + 1;i<hi; i++){
    pivo= a[i];
    j=i-1;
    while(j >= 0 && a[j] > pivo){
      a[j+1] = a[j];
      j= j-1;
    }
    a[j+1] = pivo;
  }

}