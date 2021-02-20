#include"bst.h"
#include"pilha.h"

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

void rec_preorder(no *t, void (*visit)(no*)){
  visit(t);

  if(t->esq != NULL){
    visit(t->esq);
  }

  if(t->dir != NULL){
    visit(t->dir);
  }
}

void rec_inorder(no *t, void (*visit)(no*)){
  if(t->esq != NULL){
    visit(t->esq);
  }

  visit(t);

  if(t->dir 
  != NULL){
    visit(t->dir);
  }
}

void rec_posorder(no *t, void (*visit)(no*)){
  if(t->esq != NULL){
    visit(t->esq);
  }
  
  if(t->dir 
  != NULL){
    visit(t->dir);
  }

  visit(t);
}

void inOrder(root *arvore, void (*visit)(no*)){
  if(arvore->no != NULL){
    rec_inorder(arvore->no, visit);
  }
}

void preOrder(root *arvore, void (*visit)(no*)){
  if(arvore->no != NULL){
    rec_preorder(arvore->no, visit);
  }
}

void posOrder(root *arvore, void (*visit)(no*)){
  if(arvore->no != NULL){
    rec_posorder(arvore->no, visit);
  }
}

void preOrderPilha(root *arvore, void (*visit)(no*)){
  if(arvore->no != NULL){
    preOrderPilhaNo(arvore->no,visit);
  }
}
void preOrderPilhaNo(no *node, void (*visit)(no*)){
  sentinela *pilha = initSentinela();
  push(pilha, node);
  while(pilha->prim != NULL){
    no *aux = pop(pilha);
    visit(aux);
    push(pilha, aux->dir);
    push(pilha, aux->esq);
    
  }
  destroiSentinela(pilha);
}

void inOrderPilha(root *arvore, void (*visit)(no*)){
  if(arvore->no != NULL){
    inOrderPilhaNo(arvore->no,visit);
  }
}

void inOrderPilhaNo(no *node, void (*visit)(no*)){
  sentinela *pilha = initSentinela();
  no *aux = node;
  while(aux != NULL || pilha->prim !=NULL){
    if(aux != NULL){
      push(pilha, aux);
      aux = aux ->esq;
    }else{
      aux = pop(pilha);
      visit(aux);
      aux = aux->dir;
    }
  }
  destroiSentinela(pilha);
};

void posOrderPilha(root *arvore, void (*visit)(no*)){
  if(arvore->no != NULL){
    posOrderPilhaNo(arvore->no,visit);
  }
}

void posOrderPilhaNo(no *node, void (*visit)(no*)){
  sentinela *pilha = initSentinela();
  no *ultimoVisitado = NULL;
  no *aux = node;
  while(aux != NULL || pilha->prim !=NULL){
    if(aux != NULL){
      push(pilha, aux);
      aux = aux ->esq;
    }else{
      aux = pilha->prim;
      if(aux->dir != NULL && ultimoVisitado != aux->dir){
        aux= aux->dir;
      }else{
        visit(aux);
        ultimoVisitado = pop(pilha);
      }
    }
  }
  destroiSentinela(pilha);
};