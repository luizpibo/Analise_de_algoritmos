#include <stdio.h>
#include <stdlib.h>
//Structs----------------------------------------------------- 

//Ponto de bidimencional
//x - coordenada X
//y - coordenada Y
struct Ponto{
	float x,y;
}typedef Ponto;

//Nó para lista encadeada de pontos
//P - ponteiro do ponto;
//next - ponteiro para o proximo elemento da lista
struct NoPonto{
	Ponto *p;
	struct NoPonto* next;
}typedef NoPonto;

//Distancia entre os pontos
//ini - ponteiro do ponto inicial;
//dest - ponteiro do ponto de destino;
//dist - Distancia entre os pontos;
struct Distancia{
	Ponto *ini;
	Ponto *dest;
	float dist;
}typedef Distancia;

//Nó para distancia entre os pontos
//dist - ponteiro da distancia;
//next - ponteiro para o proximo elemento da lista
struct NoDistancia{
	Distancia *dist;
	struct NoDistancia *next;

}typedef NoDistancia;
//---------------------------------------------------------------
//Funções--------------------------------------------------------

//retorna um alocação de memória para ponto e 
//atribui valores passados ou 
//nulo em caso de erro na alocação
Ponto* criaPonto(float x, float y){
	//Alocando espaço de memória para um ponteiro de ponto
	Ponto *p;
	if(p = (Ponto*) malloc(sizeof(Ponto))){
		//Atribuindo valores
		p->x = x;
		p->y = y;
		return p;
	}else{
		printf("Erro na alocação de ponto\n");
		return NULL;
	}
}

//Cria ponteiro para no de ponto 
NoPonto* criaNoPonto(){
	NoPonto *no;
	if(no=(NoPonto*) malloc(sizeof(NoPonto))){
		no->next=NULL;
		return no;
	}else{
		return NULL;
	}
}

//Gera lista de pontos com o coordenada y aleatória
//recebe quantidade de de elementos que a lista deve ter
//retorna uma lista encadeada onde os pontos x 
//-são sequenciais de 0 à qtde-1;
//gera valores aleatórios de 0 à qtde-1 para y para cada x sequencial
void geraListaDePontos(Ponto v[],int qtde){
	int i;
	for(i=0; i<qtde; i++){
		v[i].x = (rand()%qtde);
		v[i].y = (rand()%qtde);
	}
}

//calcla distancia euclideana entre dois pontos
float calculaDist(Ponto p1, Ponto p2){
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

//Imprime valores dos pontos de uma lista ordenada de NoPonto
void mostrarLista(Ponto p[], int qtde){
	int i=0;
	while(i<qtde){
		printf("Ponto %d | x-%.2f - y-%.2f\n",i,p[i].x, p[i].y);
		++i;
	}
}

//retorna o menor valor entre dois valores
float min(float x, float y){
	return (x<y)?x:y;
}

//Força bruta----------------------------------------------------
float forcaBruta(Ponto P[],int n){
	//definindo o valor minimo
	float aux;
	float min = 101;
	//laço que seleciona a posição de checagem da vez
	for(int i=0; i<n; ++i){
		//laço que pecorre o elemento de checagem;
		for(int j=i+1; j<n; ++j){
			//para cada elemento, checar distancia 
			aux = calculaDist(P[i], P[j]);
			if (aux < min){
				//Caso a distancia for menor que a minima
				min = aux;
			}
		}
	}
	//Retornando o mínimo
	return min;
}
//---------------------------------------------------------------

float tratafaixa(Ponto faixa[], int n, float d){
	float min = d;
	//margesortY(faixa, 0, n-1);
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n && (faixa[j].y)<min; ++j)
			if(calculaDist(faixa[i],faixa[j])<min)
				min = calculaDist(faixa[i],faixa[j]);
	return min;
}

//MARGE SORT-----------------------------------------------------
void margeX (Ponto v[], int ini, int mid, int fim){
	//Declarando array auxiliar
	Ponto helper [fim-ini];
	//Contadores 
	//i sendo igual o inicio;
	//j meio;
	//k contador;
	int i = ini, j = mid;
	int k = 0;

	while(i < mid && j<fim){
		if(v[i].x <= v[i].x) helper[k++] = v[i++];
		else helper[k++] = v[j++];
	}
	
	while (i<mid) helper[k++] = v[i++];
	while (j<fim) helper[k++] = v[j++];


	for(i = ini; i<fim; ++i){
		v[i] = helper[i-ini];
	}
	
}

void margeY (Ponto v[], int ini, int mid, int fim){
	//Declarando array auxiliar
	Ponto helper [fim-ini];
	//Contadores 
	//i sendo igual o inicio;
	//j meio;
	//k contador;
	int i = ini, j = mid;
	int k = 0;

	while(i < mid && j<fim){
		if(v[i].x <= v[i].x) helper[k++] = v[i++];
		else helper[k++] = v[j++];
	}
	
	while (i<mid) helper[k++] = v[i++];
	while (j<fim) helper[k++] = v[j++];


	for(i = ini; i<fim; ++i){
		v[i] = helper[i-ini];
	}
	
}

void margeSortX(Ponto A[], int ini, int fim){
	int meio;
	if(ini < fim){
		meio = (ini+fim)/2;
		margeSortX(A, ini, meio);
		margeSortX(A, meio+1, fim);
		margeX(A, ini, meio, fim);
	}
}

void margeSortY(Ponto A[], int ini, int fim){
	int meio;
	if(ini < fim){
		meio = (ini+fim)/2;
		margeSortY(A, ini, meio);
		margeSortY(A, meio+1, fim);
		margeY(A, ini, meio, fim);
	}
}

//---------------------------------------------------------------
float distmin(Ponto P[],int n){
	// se o numero de elementos do array é menor ou igual a 3 
	//usamos força bruta  
	if(n<=3)
		return forcaBruta(P,n);
	
	//definindo ponto central do array;
	int mid = n/2;

	Ponto meio = P[mid];

	float de = distmin(P,mid);
	float dd = distmin(P + mid, n - mid);
	float d = min(de, dd);
	Ponto faixa[n];
	int j = 0;
	for (int i=0; i<n; ++i){
		if (abs(P[i].x-meio.x)<d){
			faixa[j] = P[i], ++j;
		}
	}
	return min(d, tratafaixa(faixa, j, d));
}

//---------------------------------------------------------------
float mindist(Ponto p[], int n){
	margeSortX(p,0,n-1);
	return distmin(p,n);
}
int main(){
	int qtde = 100;
	Ponto v [qtde];
	geraListaDePontos(v,qtde);
    mostrarLista(v, qtde);
	printf("\n\n Min Dist: %f",mindist(v,qtde));
    return 1337;
}