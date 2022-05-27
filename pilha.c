//Mapa Estrutura de Dados I

#include <stdio.h>
#include <stdlib.h>

//Constante
#define TAM 5

//Prototype
void empilhar();
void mostrar();
char* desempilhar();

//Structs
struct pilha
{
	char *vetor[TAM];
	int inicio;
	int fim;
};

//Variaveis globais
struct pilha pilha1;
struct pilha pilha2;
char *pratos[5] = {"Vermelho", "Verde", "Azul", "Branco", "Laranja"};

//Main function
int main(void)
{
	//Inicializa variaveis da struct pilha1 e pilha2.
	pilha1.fim, pilha1.inicio = 0;
	pilha2.fim, pilha2.inicio = 0;
	
	//Mostra pilha 1 vazia.
	printf("Pilha 1 vazia: \n");
	mostrar(pilha1);
	printf("\n\n");
	
	//Empilha os pratos na pilha1.
	for (int i = 0; i < TAM; i++)
	{
		empilhar(pratos[i], &pilha1);
	}
	
	//Mostra os pratos empilhados na pilha1.
	printf("Pilha 1 cheia: \n");
	mostrar(pilha1);
	printf("\n\n");
	
	//Desempilha e ao mesmo tempo empilha na pilha2.
	for (int i = 0; i < TAM; i++)
	{
		empilhar(desempilhar(&pilha1), &pilha2);
	}
	
	//Mostra os pratos na pilha 1 desempilhados.
	printf("Pilha 1 desempilhada: \n");
	mostrar(pilha1);
	printf("\n\n");
	
	//Mostra pilha2 empilhada.
	printf("Pilha 2 empilhada: \n");
	mostrar(pilha2);	
}

//Functions
//Espera um elemento prato e uma struct tipo pilha e empilha o elemento.
void empilhar(char *prato, struct pilha *p)
{
	if (p->fim == TAM)
	{
		printf("Pilha cheia!\n");
		system("pause");
	}
	p->vetor[p->fim] = prato;
	p->fim++;
}

//Espera uma struct tipo pilha e retorna o elemento desempilhado.
char* desempilhar(struct pilha *p)
{
	char *elemento;
	if (p->fim == p->inicio)
	{
		printf("Pilha vazia!");
		system("pause");
	}	
	elemento = p->vetor[p->fim - 1];
	p->vetor[p->fim - 1] = 0;
	p->fim--;
		
	return elemento;	
}

//Espera uma struct tipo pilha e imprime os dados.
void mostrar(struct pilha p)
{
	for(int i = 0; i < TAM; i++)
	{
		printf("%s ", p.vetor[i]);
	}
}
