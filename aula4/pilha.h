#ifndef PILHA_H_
#define PILHA_H_

#include<stdlib.h>
#include<stdio.h>

typedef struct celula{
  void *item;
  struct celula *prox;
} celula;

typedef struct sentinela{
  celula *prim;
  celula *ult;
} sentinela;

sentinela *initSentinela();
void push(sentinela *sentinela, void * item);
void *pop(sentinela *sentinela);
void destroiSentinela(sentinela *sentinela);

#endif // !PILHA_H_

