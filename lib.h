#define MAX 13
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stddef.h>
typedef struct {
	int chave;
	int valor;
} Telemento;

typedef struct {
    int numUnico, dataMes, dataAno;
    char nome [100];
} Cartao;

typedef struct{
    char cpf [11], nome[100], endereco[200];
    Cartao cartoes[10];
} Usuario;

typedef struct {
    char descricao [200];
    float valor;
    Usuario usuario;
} Compra;


struct no{
        Cartao cartao;
        struct no *proximo;
};

typedef struct no* Tno;



typedef struct{
        Tno elemento[MAX];
        int n;
} TLista;

int criar(TLista *L);
int inserir(TLista *L, int hash, Cartao cartao);
void exibir(TLista L);
int hashing(int chave);

