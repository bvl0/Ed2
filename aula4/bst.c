#include"bst.h"

root *criaArvoreVazia(){
  root *arvoreVazia = malloc(sizeof(root));
  arvoreVazia->no = NULL;

  return arvoreVazia;
}

no *criaNo(int n, no *esq, no *dir){
  no *novo = malloc(sizeof(no));
  
  novo->chave = n;
  novo->esq = esq;
  novo->dir = dir;

  return novo;
}

void insereNo(root *arvore, int n){
  if (arvore != NULL){
    if(arvore->no == NULL){
      arvore->no = criaNo(n, NULL, NULL);
    }

    no *noAtual = arvore->no;
    no *noAnterior = arvore->no;

    while(noAtual != NULL){
      noAnterior = noAtual;
      if(n < noAtual->chave){
        noAtual = noAtual->esq;
      }
      else if(n > noAtual->chave){
        noAtual = noAtual->dir;
      }
      else{
        return;
      }
    }
    
    if(n < noAnterior->chave){
      noAnterior->esq = criaNo(n, NULL, NULL);
    }
    else{
      noAnterior->dir = criaNo(n, NULL, NULL);
    }
  }
}

void destroiArvore(root *arvore){
  no *noAtual = arvore->no;
  destroiArvoreAux(noAtual);
  free(arvore);
}

void destroiArvoreAux(no *no){
  if(no->esq != NULL){
    destroiArvoreAux(no->esq);
  }
  if(no->dir != NULL){
    destroiArvoreAux(no->dir);
  }

  free(no);
  return;
}

int tamanhoArvore(root* arvore){
  if(arvore->no == NULL){
    return -1;
  }
  else{
    return medeNos(arvore->no);
  }
}
int medeNos(no *no){
  int esq = 0;
  int dir = 0;

  if(no->esq != NULL){
    esq = 1 + medeNos(no->esq);
  }
  if(no->dir != NULL){
    dir = 1+ medeNos(no->dir);
  }

  if(dir > esq){
    return dir;
  }
  else{
    return esq;
  }
}