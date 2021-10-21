#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QUANTIDADE_LINHAS 21
#define QUANTIDADE_COLUNAS 2

void mostraPontos(float matriz[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]){
	int contLinha, contColuna;
	printf("\n----Pontos-----\n");
	for(contLinha = 0; contLinha<QUANTIDADE_LINHAS; contLinha++){
		printf("Linha %2d - ",contLinha);
	for (contColuna = 0; contColuna < QUANTIDADE_COLUNAS; contColuna++){
		if(contColuna==0){

			printf("x-%.2f |",matriz[contLinha][contColuna]);
		}else{
			printf("y-%.2f\n",matriz[contLinha][contColuna]);
		}
		
		}
	}
}

//calcula distancia entre pontos
float distanciaDimensional(float px, float py, float qx, float qy){

	float result = sqrt( pow((qx-px), 2)+pow((qy-py), 2));

	return result;
}

float minDist(float matriz[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS], int qtde){
	if(qtde<=3){

	}
	int m = qtde/2;
	dl = minDist(matriz,m);
	dr=minDist(matriz+m, qtde-m);
	d=(dl<dr);
	
}

int main(){
	float pontos[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS];
	int contLinha, contColuna;
	int x=0;

	for(contLinha = 0; contLinha<QUANTIDADE_LINHAS; contLinha++){
		for (contColuna = 0; contColuna < QUANTIDADE_COLUNAS; contColuna++){
			if(contColuna==0){
				pontos[contLinha][contColuna] = x;
				x++;	
			}else{
				pontos[contLinha][contColuna] = rand()%QUANTIDADE_LINHAS;	
			}
			
		}
	}

	mostraPontos(pontos);

	printf(
		"\nDistancia entre x1:%.2f | y1:%.2f - x2:%.2f | y2:%.2f -- %f\n\n"
		,pontos[1][0],pontos[1][1],pontos[19][0],pontos[19][1],
		distanciaDimensional(pontos[1][0],pontos[1][1],pontos[19][0],pontos[19][1]
	));

	printf("hello word\n");
    return 1337;
}