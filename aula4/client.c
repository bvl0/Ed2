#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"bst.h"

int main(int argc, char *argv[]){
  int n = atoi(argv[1]);
  root *raiz = criaArvoreVazia();
  srand(time(NULL));

  for(int i=0; i<n; i++){
    insereNo(raiz, rand());
  }

  printf("tamanho da arvore %i",tamanhoArvore(raiz));
  destroiArvore(raiz);
}