#include"shakerSort.h"

void sort(Item *a, int lo, int hi) {
  int troca=1;

  while(troca == 1 && lo < hi){
    troca = 0;

    for(int i  = lo; i < hi - 1; i++){
      if(less(a[i+1],a[i])){
        exch(a[i],a[i+1]);
        troca=1;
      }  
    }
    hi--;
    for(int i  = hi; i > lo ; i--){
      if(less(a[i],a[i-1])){
        exch(a[i-1],a[i]);
        troca=1;
      }  
    }
    lo++;
  }
}