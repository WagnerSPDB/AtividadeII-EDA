#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 13
//Tipo pessoa
typedef struct {
    int numUnico, dataMes, dataAno;
    char nome [100];
} Cartao;

typedef struct no{
    Cartao cartao;  //objeto cartao
    struct no *proximo;  //Ponteiro para próximo nó
} Cno;

typedef struct{
    Cno *inicio;
    int tam;
} Clista;

typedef struct{
    int cpf;
    char nome [100], endereco[200];
    Cartao* cartoes[10];
    int tam;
} Usuario;

typedef struct uno{
    Usuario usuario;
    struct uno *proximo;
} Uno;

typedef struct{
    Uno *inicio;
    int tam;
} Ulista;


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
Cno* buscarNo(int num, Cno *inicio);
Cartao* buscarCartaoTabela(int num);
void imprimirCartao(Cartao c);
void imprimirListaC(Cno *inicio);
void imprimirTabelaC();
void imprimirUsuario(Usuario u);
void imprimirListaU(Uno *inicio);
void imprimirTabelaU();
