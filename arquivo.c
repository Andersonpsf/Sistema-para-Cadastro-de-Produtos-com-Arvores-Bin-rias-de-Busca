#include <stdio.h>
#include <stdlib.h>
typedef struct No {
	int chave; //chave de busca
	float preco;
	char item[50];
	struct No *esquerda;
	struct No *direita; 
	} No;
	
	No* criaNo(int valor) {
		No* novoNo = (No*)malloc(sizeof(No));
		novoNo->chave = valor;
		printf("Nome do item:");
		scanf("%s", novoNo->item);
		printf("Preco do item: ");
		scanf("%f", novoNo->preco);
		novoNo->esquerda = novoNo->direita = NULL;
		return novoNo;
	}
	
	No* busca(No* raiz, int valor) {
		if (raiz == NULL || raiz->chave == valor)
			return raiz;
		if (valor < raiz->chave)
			return busca(raiz->esquerda, valor);
		else
			return busca(raiz->direita, valor);
	}

	No* insere(No* raiz, int valor) {
		if (raiz == NULL)
			return criaNo(valor);
		if (valor < raiz->chave) {
			raiz->esquerda = insere(raiz->esquerda, valor);
			return raiz;
		}
		else if (valor > raiz->chave) {
			raiz->direita = insere(raiz->direita, valor);
			return raiz;
		}
		else // O valor já existe, somente retornar a raiz atual
		return raiz;
}

int main(){
	
	No* novo=criaNo(1);
	insere(novo, 3);
	insere(novo, 5);
	No* retorno = busca(novo,3);
	printf("%d /n", retorno->chave);
	printf("%s/n",retorno->item);
}
