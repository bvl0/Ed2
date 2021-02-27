#ifndef INSERTSORT_H_
#define INSERTSORT_H_

#include<stdio.h>
#include<stdlib.h>
#include"item.h"

void sort(Item *a, int lo, int hi){
  int j, pivo;

  for(int i= lo + 1;i<hi; i++){
    pivo= i;
    j=i+1;
    while(pivo< j){
      exch(a[j-1], a[j]);
    }
  }

}

#endif // !INSERTSORT_H_