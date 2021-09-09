#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringMatching(char* vet, char* palavra){
	int i,j = 0;
	int ret = -1;
	if(strlen(vet)<strlen(palavra)){
		return -2;
	}
	
	if(strlen(vet)==strlen(palavra)){
		if(!strcmp(vet,palavra)){
			return 0;
		}
	}
	
	for(i=0; i<strlen(vet); i++){
		if(vet[i]==palavra[0]){
			printf("\nAchou uma letra %c na posicao %d\n\n",palavra[0],i);
			for(j=1; j<strlen(vet)-strlen(palavra); j++){
				printf("Comparando a posicao %.2d do vetor com a posicao %d da palavra\n", i+j, j);
				if(vet[i+j]!=palavra[j]){
					break;
				}
			}
			if(j==strlen(palavra)){
				return i;
			}
		}
		
	}
	return ret;
}

int main(int argc, char *argv[]) {
	char string[14] = {"abcdeamorabcde"};
	char palavra[5] = {"amor"};
	printf("Strign 1 - %s\n", string);
	printf("String 2 - %s\n", palavra);
	int resultado = stringMatching(string, palavra);
	printf("resultado %d\n", resultado);
	return 0;
}
