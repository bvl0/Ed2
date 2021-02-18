#ifndef BST_H_
#define BST_H_

#include<stdlib.h>
#include<stdio.h>

typedef struct no {
  int chave;
  struct no *esq;
  struct no *dir;
}no;

typedef struct root {
  no *no;
}root;

root *criaArvoreVazia();
no *criaNo(int n, no *esq, no *dir);
void insereNo(root *arvore, int n);
void destroiArvore(root *arvore);
void destroiArvoreAux(no *no);//q deveria se chamar destroi nó mas fiquei com preguiça de trocar
int tamanhoArvore(root* arvore);
int medeNos(no *no);
#endif // !BST_H_


