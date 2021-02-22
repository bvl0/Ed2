#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"bst.h"

void printaNo(no* no) {
    // printf("%d ", tree->key);
}


int main(int argc, char *argv[]){
  int n = atoi(argv[1]);
  root *raiz = criaArvoreVazia();
  srand(time(NULL));

  for(int i=0; i<n; i++){
    insereNo(raiz, rand());
  }

  // printf("tamanho da arvore %i",tamanhoArvore(raiz));
  // destroiArvore(raiz);
  clock_t start = clock();
  posOrder(raiz, printaNo);
  clock_t end = clock();
  printf("recursive  time : %lf seconds\n", ((double)end - start) / CLOCKS_PER_SEC);

  start = clock();
  posOrderPilha(raiz, printaNo);
  end = clock();
  printf("non recursive time: %lf seconds\n", ((double)end - start) / CLOCKS_PER_SEC);

}