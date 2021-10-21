#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10000
/*

    ## Algorítmos de ordenação e comparação das suas complexidades
    ----------------------------------
    * Para essa comparação vou usar vetor de inteiros com 10k posições.
    * para cada alg vou analisar sua complexidade e função de recursividade.
    * vou repetir o processo 5 vezes com arrays de dados diferentes.
    * 
*/

//
//Consiste em realizar trocas sucessivas buscando a melhor posição para o elemento;
//Complexidade O(N²);
//

int bubbleSort(int A[], int tam)
{
    int i = 0, j, aux, trocou = 1;
    int count = 0;
    while (trocou)
    {
        trocou = 0;
        count += 1;
        for (j = 1; j < tam - i; j++)
        {
            if (A[j - 1] > A[j])
            {
                aux = A[j - 1];
                A[j - 1] = A[j];
                A[j] = aux;
                trocou = 1;
                count += 4;
            }
        }
        i++;
        count += 1;
    }
    return count;
}

//
//Heap sort:
//

//
//Insertion sort:
//

int insertionSort(int A[], int size)
{
    int i, j, key;
    int count = 0;
    for (i = 1; i < size; i++)
    {
        key = A[i];
        j = i - 1;
        count += 2;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
            count += 2;
        }
        A[j + 1] = key;
        count += 1;
    }
    return count;
}

//
//Merge sort: alg com base em divisão e conquista, faz divisões sucessivas no vetor
//faz o marge para ordernar sub vetores;
//Complexidade: O(N log N);
//

/*
void margeSort(int A[], int ini, int fim){
    int meio;
    if(ini < fim){
        meio = (ini+fim)/2;
        margeSort(A, ini, meio);
        margeSort(A, meio+1, fim);
        merge(A, ini, meio, fim);
    }
}
*/

//
//Quick sort: divisão e conquista
// Selecione um valor como um separador (pivô). A partir daí ele cria duas listas:
// A primeira com os valores menores que o pivô e otra com os valores maiores que o pivô;
// Repete o processo recursivamente criando listas menores até que estas tenham apenas elementos;
// Diferença entre o margeSort:
// Aquele faz uma divisão simples e o marge (mais complicado) depois
// complexidade: pior caso O(n²) caso médio O(n log n); melhor caso (n log n);
//

int quickSort(int A[], int ini, int fim)
{
    int i = ini, f = fim, pivo = A[(ini + fim) / 2], aux;
    int count = 0;
    do
    {
        while (A[i] < pivo)
        {
            i++;
            count += 1;
        }

        while (A[f] > pivo)
        {
            f--;
            count += 1;
        }

        if (i <= f)
        {
            aux = A[f];
            A[i++] = A[f];
            A[f--] = aux;
            count += 3;
        }
    } while (i <= f);

    if (ini < f)
        count += quickSort(A, ini, f);
    if (i < fim)
        count += quickSort(A, i, fim);
    return count;
}

//
//Selection sort: procura o menor/maior elemento do vetor a cada interação;
//Complexidade: O(n²);
//

int selectionSort(int A[], int tam)
{
    int i = 0, j = 0, aux, min;
    int count = 0;
    for (i = 0; i < tam - 1; i++)
    {
        min = i;
        count += 1;
        for (j = i + 1; j < tam; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
                count += 1;
            }
        }
        aux = A[i];
        A[i] = A[min];
        A[min] = aux;
        count += 3;
    }
    return count;
}

//
//Shell sort:
/*
    Criado por Donald Shell em 1959, 
    é o mais eficiente alg de classificação dentre os de complexidade quadrática;
    é um refinamento do insert sort,

*/
//

int shellSort(int A[], int tam)
{
    int i, j, aux, gap = 1;
    int count = 0;
    while (gap < tam)
        gap = (gap * 3) + 1;
    count += 1;
    while (gap > 1)
    {
        gap /= 3;
        count += 1;
        for (i = gap; i < tam; i++)
        {
            aux = A[i];
            j = i - gap;
            count += 2;
            while ((j >= 0) && (aux < A[j]))
            {
                A[j + gap] = A[j];
                j -= gap;
                count += 2;
            }
            A[j + gap] = aux;
            count += 1;
        }
    }
    return count;
}

void geraArrayAleatorio(int v[])
{
    int i = 0;
    srand(time(NULL));
    while (i < TAM)
    {
        v[i] = (rand() % TAM) + (-TAM / 2);
        i++;
    }
}

void copiaArray(int v1[], int v2[])
{
    int i = 0;
    while (i < TAM)
    {
        v2[i] = v1[i];
        i++;
    }
}

void mostraArray(int v[])
{
    int i = 0;
    printf("Mostra Array: \n");
    while (i < TAM)
    {
        printf("|%.5d", v[i]);
        i++;
    }
    printf("\n");
}

void mostraCompara()
{
    //Declarando arrays
    int v1[TAM], v2[TAM];

    //Gerando array com valores aleatórios
    geraArrayAleatorio(v1);

    //Exibindo array inicial
    //mostraArray(v1);

    //copiando array
    copiaArray(v1, v2);
    printf("\n\n");

    //Sorts
    printf("Número de trocas bubble...: %d\n", bubbleSort(v2, TAM));
    copiaArray(v1, v2);
    printf("Número de trocas Selection: %d\n", selectionSort(v2, TAM));
    copiaArray(v1, v2);
    printf("Número de trocas Insertion: %d\n", insertionSort(v2, TAM));
    copiaArray(v1, v2);
    printf("Número de trocas Shell....: %d\n", shellSort(v2, TAM));
    copiaArray(v1, v2);
    printf("Número de trocas Quick....: %d\n", quickSort(v2, 0, TAM));
    printf("\n");
}
int main()
{
    mostraCompara();
    mostraCompara();
    mostraCompara();
    mostraCompara();
    mostraCompara();
    return 1337;
}