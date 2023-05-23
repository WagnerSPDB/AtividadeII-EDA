#include"lib.h"

int main(void) {
	int op;
	TLista C;
	Cartao cartao;
	criar(&C);
	int hash;
	do{
    //Exibir menu
        system("cls");
        puts("\n\t\t\t\tEDITOR DE LISTAS\n");
        puts("\t1  - EXIBIR LISTA\n \t2  - INSERIR UM ELEMENTO\n \t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção

    	switch(op)
        	{
        		case 1:{
        			exibir(C);
					break;
				}

				case 2:{
					printf("Informe o numero do cartao: ");
	                scanf("%d", &cartao.numUnico);

	                printf("Informe o nome do titular: ");
	                scanf(" %[^\n]", cartao.nome);

	                printf("Informe a data de validade do cartao (mm aa): ");
	                scanf("%d %d", &cartao.dataMes, &cartao.dataAno);
	                fflush(stdin);
	                hash = hashing(cartao.numUnico);
	                inserir(&C, hash, cartao);
					break;
				}
        	// Outra opção nao oferecida
    		default:
    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;

        }
	getch();
    }while(op!=0);

  system("PAUSE");
  return 0;
}
