#include "pilha.h"

sentinela *initSentinela(){
  sentinela *sentinela = malloc(sizeof(sentinela));
  sentinela->prim = sentinela->ult = NULL;
}

void push(sentinela *sentinela, void * item){
  celula *celula = malloc(sizeof(celula));
  celula->item = item;

  if(sentinela->prim == NULL){
    sentinela->prim = celula;
    sentinela->ult = celula;
    celula->prox = NULL;
  } else{
    celula->prox = sentinela ->prim;
    sentinela->prim = celula;
  }
}

void *pop(sentinela *sentinela){
  celula *aux = sentinela->prim;
  void *retorno = aux->item;
  if(sentinela->prim == sentinela->ult){
    sentinela->prim = sentinela->ult = NULL;
    free(aux);
    return retorno;
  }else{
    sentinela->prim = aux ->prox;
    free(aux);
    return retorno;
  }
}

void destroiSentinela(sentinela *sentinela){
  while(sentinela->prim != NULL){
    free(pop(sentinela));
  }
  free(sentinela);
}