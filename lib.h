#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 13
//Tipo pessoa
typedef struct cmno Compra;

typedef struct {
    int numUnico, dataMes, dataAno;
    char nome [100];
    Compra *a;
} Cartao;

typedef struct{
    int cpf;
    char nome [100], endereco[200];
    Cartao* cartoes[10];
    int tam;
} Usuario;

typedef struct{
    int id;
    float valor;
    char descricao[200];
    Usuario* usuario;
} DadoCompra;

typedef struct no{
    Cartao cartao;  //objeto cartao
    struct no *proximo;  //Ponteiro para próximo nó
} Cno;

typedef struct{
    Cno *inicio;
    int tam;
} Clista;

typedef struct uno{
    Usuario usuario;
    struct uno *proximo;
} Uno;

typedef struct{
    Uno *inicio;
    int tam;
} Ulista;

typedef struct cmno{
	DadoCompra dado;
	int fator_b;
	struct cmno* esq;
	struct cmno* dir;
} Compra;




Clista* criarListaC();
Ulista* criarListaU();
void inicializarC();
void inicializarU();
Cartao criarCartao();
Usuario criarUsuario();
int hashing(int num);
void inserirInicioC(Cartao c, Clista *lista);
void inserirInicioU(Usuario u, Ulista *lista);
void inserirTabelaC();
void inserirTabelaU();
Compra* criarCompraNo(DadoCompra dado);
Compra* criarCompra();
Compra* inserirCompra(Compra* a, DadoCompra dado);
Cno* buscarNo(int num, Cno *inicio);
Uno* buscarNoUsu(int num, Uno *inicio);
Cartao* buscarCartaoTabela(int num);
Usuario* buscarUsuarioTabela(int num);
void imprimirCartao(Cartao c);
void imprimirListaC(Cno *inicio);
void imprimirTabelaC();
void imprimirUsuario(Usuario u);
void imprimirListaU(Uno *inicio);
void imprimirTabelaU();
void imprime(Compra* a);
void percorrerEmOrdem(Compra* raiz);
int altura_AVL(Compra* a);
int calcula_FB(Compra* a);
Compra* rotacao_simples_esquerda(Compra* a);
Compra* rotacao_simples_direita(Compra* a);
Compra* balanceamento(Compra* a);
Compra *balanceio_direita(Compra *a);
Compra *balanceio_esquerda(Compra *a);
