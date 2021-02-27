#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "selectionSort.h"
extern void sort(Item *a, int lo, int hi);

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);

  Item *array = malloc(n*sizeof(Item));

  for(int i = 0; i<n; i++){
    int j=0;
    scanf("%i",&j);
    array[i] = (Item) j;
  }

  sort(array,0,n);

  for(int i=0; i<n; i++){
    printf("%i \n",key(array[i]));
  }

  free(array);

}