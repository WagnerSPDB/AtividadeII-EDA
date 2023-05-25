#include "lib.h"
Clista *tabelaC[MAX];
Ulista *tabelaU[MAX];

// Criar lista vazia retornando seu endereco
Clista* criarListaC(){
    Clista *c = malloc(sizeof(Clista));
    c->inicio = NULL;
    c->tam = 0;
    return c;
}

Ulista* criarListaU(){
    Ulista *u = malloc(sizeof(Ulista));
    u->inicio = NULL;
    u->tam = 0;
    return u;
}

//Inicializacao da tabela
void inicializarC(){
    int i;
    for(i=0; i < MAX; i++){
        tabelaC[i] = criarListaC();
    }
}

void inicializarU(){
    int i;
    for(i=0; i < MAX; i++){
        tabelaU[i] = criarListaU();
    }
}

Cartao criarCartao(){
    Cartao c;
    printf("Informe o numero do cartao: ");
    scanf("%d", &c.numUnico);
    printf("Informe o nome do titular: ");
    scanf("%*c");
    fgets(c.nome, 100, stdin);
    printf("Informe a data de validade do cartao (mm aa): ");
    scanf("%d %d", &c.dataMes, &c.dataAno);
    return c;
}

Usuario criarUsuario(){
    Usuario u;
    Cartao *aux;
    int n;
    printf("Informe o cpf: ");
    scanf("%d", &u.cpf);
    printf("Informe o nome: ");
    scanf("%*c");
    fgets(u.nome, 100, stdin);
    printf("Informe o endereco: ");
    scanf("%*c");
    fgets(u.endereco, 200, stdin);
    do{
        printf("Informe o numero do cartao que deseja vincular: ");
        scanf("%i", &n);
        aux = buscarCartaoTabela(n);
        if(aux != NULL){
            u.cartoes[u.tam] = aux;
        }else{
            printf("Cartão inexistente!");
            return;
        }
    }while(u.cartoes[u.tam] == NULL);
    u.tam++;
    return u;
}

//hashing
int hashing(int num){
    return num % MAX;
}

//Inserir no inicio da lista
void inserirInicioC(Cartao c, Clista *lista){
    Cno *no = malloc(sizeof(Cno));
    no->cartao = c;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

void inserirInicioU(Usuario u, Ulista *lista){
    Uno *no = malloc(sizeof(Uno));
    no->usuario = u;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

void inserirTabelaC(){
    Cartao car = criarCartao();
    int indice = hashing(car.numUnico);
    inserirInicioC(car, tabelaC[indice]);
}

void inserirTabelaU(){
    Usuario usu = criarUsuario();
    int indice = hashing(usu.cpf);
    inserirInicioU(usu, tabelaU[indice]);
}

//Buscar elemento na lista
Cno* buscarNo(int num, Cno *inicio){
    while(inicio != NULL) {
        if(inicio->cartao.numUnico == num)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL; //Caso o cartao nao for encontrada
}

//Buscar um cartao na tabela
Cartao* buscarCartaoTabela(int num){
    int indice = hashing(num);
    Cno *no = buscarNo(num, tabelaC[indice]->inicio);
    if(no)
        return &no->cartao;
    else
        return NULL;
}

void imprimirCartao(Cartao c){
    printf("\t\t    ^\n\t    Nome: %s\t    Numero unico: %d\n\t    Data de validade: %d/%d \n\n", c.nome, c.numUnico,c.dataMes, c.dataAno);
}

void imprimirListaC(Cno *inicio){
    while(inicio != NULL) {
        imprimirCartao(inicio->cartao);
        inicio = inicio->proximo;
    }
}

//Imprimir tabela
void imprimirTabelaC(){
    int i;
    printf("\n----------------- Tabela ---------------------\n\n");
    for(i=0; i < MAX; i++){
        printf("\t\tIndice %d\n", i);
        imprimirListaC(tabelaC[i]->inicio);
    }
    printf("\n---------------- FIM Tabela --------------------\n");
}

void imprimirUsuario(Usuario u){
    printf("\t\t    ^\n\t    Nome: %s\t    CPF: %d\n\t    Endereço: %s \n", u.nome, u.cpf, u.endereco);
    printf("Cartoes vinculados: ");
    for(int i = 0; i < u.tam; i++){
        printf("Numero: %d, Titular: %s", u.cartoes[i]->numUnico, u.cartoes[i]->nome);
    }
}

void imprimirListaU(Uno *inicio){
    while(inicio != NULL) {
        imprimirUsuario(inicio->usuario);
        inicio = inicio->proximo;
    }
}

//Imprimir tabela
void imprimirTabelaU(){
    int i;
    printf("\n----------------- Tabela ---------------------\n\n");
    for(i=0; i < MAX; i++){
        printf("\t\tIndice %d\n", i);
        imprimirListaU(tabelaU[i]->inicio);
    }
    printf("\n---------------- FIM Tabela --------------------\n");
}

