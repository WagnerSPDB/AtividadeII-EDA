#include"lib.h"

int criar(TLista *L){
	int i=0;
	for(i=0;i<MAX;i++)
		L->elemento[i] = NULL;
        L->n=0;
	return 1;
}

int inserir(TLista *L, int hash, Cartao cartao){
	Tno novo;
	novo = (Tno) malloc (sizeof(Tno));
	if(novo == NULL) return 0;

	novo->cartao = cartao;
	novo->proximo = NULL;

	if(L->elemento[hash] == NULL)
		L->elemento[hash] = novo;
	else{
		novo->proximo = L->elemento[hash];
		L->elemento[hash] = novo;
	}
	L->n+=1;
	return 1;
}

void exibir(TLista L){
	int i;
	Tno aux;
	if(L.n == 0){
		printf("Tabela vazia\n");
		return;
	}
	else{
		for(i = 0; i < MAX; i++){
			if(L.elemento[i] != NULL){
				printf("--------- Indice %d -------\n", i);
				aux = L.elemento[i];
				while(aux != NULL){
				printf("Chave = %d \n", aux->cartao.numUnico);
				printf("Valor = %s \n\n", aux->cartao.nome);
				aux = aux->proximo;
				}
			}
		}
	}
}

int hashing(int chave){
	return chave % MAX;
}

