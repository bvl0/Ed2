#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include<time.h>
extern void sort(Item *a, int lo, int hi);

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  FILE* entrada = fopen(argv[2],"r");

  Item *array = malloc(n*sizeof(Item));



  for(int i = 0; i<n; i++){
    int j=0;
    fscanf(entrada, "%i",&j);
    array[i] = (Item) j;
  }
  clock_t before = clock();
  sort(array,0,n);
  clock_t after = clock();

  printf("Sorting took %lf seconds\n ", (double)(after - before) / CLOCKS_PER_SEC);
  // for(int i=0; i<n; i++){
  //   printf("%i \n",key(array[i]));
  // }

  free(array);
  fclose(entrada);

}