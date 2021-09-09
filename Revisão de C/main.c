#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct que contem o array e o numero de elementos desse array
typedef struct No{
	int* ptr;
	int len;
} No;

No* criarNo(void){
	No* no = (No *)malloc(sizeof(No));
	no->ptr = NULL;
	no->len = 0;
	return no;
}

int* retornaVetorDeInteiros(int qtde){
	if(qtde<1 || qtde>3000){
		printf("\n QTDE DE ELEMENTOS INVALIDA !!\n");
		return NULL;
	}
	return (int *)malloc(sizeof(int)*qtde);
}
void mostrarVetInt(int *vet, int qtde){
	int cont;
	printf("\n");
	for(cont = 0; cont<qtde; cont++){
		printf(" - %d ", vet[cont]);
	}
	printf("\n");
}

No* retornaValoresAcimaDaMediaVetInt(int *vet, int qtde){
	No *valoresAcimaDaMedia = criarNo();
	float media, somaDosValores = 0;
	int qtdeDeElementosDoVetor, cont;
	qtdeDeElementosDoVetor = qtde;

	for(cont = 0; cont<qtdeDeElementosDoVetor; cont++){
		somaDosValores=somaDosValores+vet[cont];
	}
	printf("\n Soma Dos valores - %.2f", somaDosValores);
	
	media = somaDosValores/qtdeDeElementosDoVetor;
	printf("\n Media - %.2f", media);
	for(cont = 0; cont<qtdeDeElementosDoVetor; cont++){
		if(vet[cont]>media){
			valoresAcimaDaMedia->ptr = (int*) realloc(valoresAcimaDaMedia->ptr, sizeof(int)*valoresAcimaDaMedia->len+1);
			valoresAcimaDaMedia->ptr[valoresAcimaDaMedia->len] = vet[cont];
			valoresAcimaDaMedia->len++;
		}
	}

	return valoresAcimaDaMedia;
}
int main(int argc, char *argv[]) {
	No* vetorInicial = criarNo();
	vetorInicial->ptr = retornaVetorDeInteiros(10);
	vetorInicial->len = 10;
	vetorInicial.ptr = {0,1,2,3,4,5,6,7,8,9};
	
	printf("\nValor do vetor inicial ");
	mostrarVetInt(vet,10);
	No *retorno;
	printf("\nQUESTAO 1\n");
	retorno = retornaValoresAcimaDaMediaVetInt(vet, 10);
	printf("\nQuantidade de elementos do vetor de elementos acima da media - %d\n",retorno->len);
	mostrarVetInt(retorno->ptr, retorno->len);
 	getchar();
	return 0;

}


