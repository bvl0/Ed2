#include"selectionSort.h"

void sort(Item *a, int lo, int hi){
  for(int i =lo; i<hi;i++) {
    int j = i;
    int menor = j;
    while(j < hi){
      if(less(a[j], a[menor])){
        menor = j;
      }
      j++;
    }
    compexch(a[i],a[menor]);
  }
}