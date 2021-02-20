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
void rec_preorder(no *t, void (*visit)(no*));
void rec_inorder(no *t, void (*visit)(no*));
void rec_posorder(no *t, void (*visit)(no*));
void inOrder(root *arvore, void (*visit)(no*));
void preOrder(root *arvore, void (*visit)(no*));
void posOrder(root *arvore, void (*visit)(no*));
void preOrderPilha(root *arvore, void (*visit)(no*));
void preOrderPilhaNo(no *node, void (*visit)(no*));
void inOrderPilha(root *arvore, void (*visit)(no*));
void inOrderPilhaNo(no *node, void (*visit)(no*));
void posOrderPilha(root *arvore, void (*visit)(no*));
void posOrderPilhaNo(no *node, void (*visit)(no*));
#endif // !BST_H_


