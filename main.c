#include "lib.h"

// Tabela que um vetor de ponteiros para listas

int main() {
    int opcao, num;
    Cartao *c;
    inicializarC();
    Usuario *u;
    inicializarU();
    DadoCompra dado;
    Compra *a;

    do{
        printf("\t\t\tEditor de listas\n\t0 - Sair\n\t1 - Inserir novo cartao\n\t2 - Inserir novo usuario\n\t"
               "3 - Inserir nova compra\n\t4 - Buscar cartao\n\t5 - Imprimir tabela de cartoes\n\t6 - Imprimir tabela de usuarios\n");
        scanf("%d", &opcao);
        switch(opcao){
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            inserirTabelaC();
            break;
        case 2:
            inserirTabelaU();
            break;
        case 3:
           a = criarCompra(dado);
            break;
        case 4:
            printf("Qual o numero do cartao a ser buscado? ");
            scanf("%d", &num);
            c = buscarCartaoTabela(num);
            if(c) {
                printf("\tCartao encontrado! \nNumero do Cartao: %d \nNome: %sData de validade: %d/%d\n", c->numUnico, c->nome, c->dataMes, c->dataAno);
            }

            else
                printf("Cartao nao encontrado!\n");
            break;
        case 5:
            imprimirTabelaC();
            break;
        case 6:
            imprimirTabelaU();
            break;
        case 7:
            imprime(a);
            break;
        default:
            printf("Opção Invilida!\n");
        }
    }while(opcao != 0);

    return 0;
}
#include "lib.h"

// Tabela que um vetor de ponteiros para listas

int main() {
    int opcao, num;
    Cartao *c;
    inicializarC();
    Usuario *u;
    inicializarU();
    DadoCompra dado;
    Compra *a;

    do{
        printf("\t\t\tEditor de listas\n\t0 - Sair\n\t1 - Inserir novo cartao\n\t2 - Inserir novo usuario\n\t"
               "3 - Inserir nova compra\n\t4 - Buscar cartao\n\t5 - Imprimir tabela de cartoes\n\t6 - Imprimir tabela de usuarios\n");
        scanf("%d", &opcao);
        switch(opcao){
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            inserirTabelaC();
            break;
        case 2:
            inserirTabelaU();
            break;
        case 3:
           a = criarCompra(dado);
            break;
        case 4:
            printf("Qual o numero do cartao a ser buscado? ");
            scanf("%d", &num);
            c = buscarCartaoTabela(num);
            if(c) {
                printf("\tCartao encontrado! \nNumero do Cartao: %d \nNome: %sData de validade: %d/%d\n", c->numUnico, c->nome, c->dataMes, c->dataAno);
            }

            else
                printf("Cartao nao encontrado!\n");
            break;
        case 5:
            imprimirTabelaC();
            break;
        case 6:
            imprimirTabelaU();
            break;
        case 7:
            imprime(a);
            break;
        default:
            printf("Opção Invilida!\n");
        }
    }while(opcao != 0);

    return 0;
}
