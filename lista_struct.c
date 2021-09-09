#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int chave;
	struct no *prox;
} node;

int func(node *p) {
	int ret=0;
	int i;
  	if (p != NULL) {
    	ret = func(p->prox)+1;
    	printf("%d", p->chave);
    for(i=0;i<ret;i++)
    	printf("%c",'*');
  }
  return ret;
}
node* alocarNode(){
	return (node*)malloc(sizeof(node*));
}
void inicializaAtribuiValorNode(int valor, node* no){
	no->chave=valor;
	no->prox=NULL;
}
int main(int argc, char *argv[]) {
	int i;
	node* raiz;
	node* aux;
	raiz = alocarNode();
	aux = alocarNode();
	inicializaAtribuiValorNode(11,aux);
	inicializaAtribuiValorNode(10,raiz);
	raiz->prox = aux;
	printf("valor raiz - %d ",raiz->chave);
	printf("valor aux - %d \n",aux->chave);
	for(i=2; i<10; i++){
		aux->prox = alocarNode();
		inicializaAtribuiValorNode(i+10, aux->prox);
		aux=aux->prox;
	}
	aux->prox=NULL;
	aux = raiz;
	while(aux!=NULL){
		printf("%d - ", aux->chave);
		aux = aux->prox;
	}
	printf("\n");
	i = func(raiz);
	return 0;
}
