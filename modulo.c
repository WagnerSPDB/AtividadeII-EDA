#include "lib.h"
Clista *tabelaC[MAX];
Ulista *tabelaU[MAX];
int ProxId = 1;
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
    u.tam = 0;
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

Compra* criarCompra(DadoCompra dado) {
    Compra* novoNo = (Compra*)malloc(sizeof(Compra));
    novoNo->dado = dado;
    novoNo->dado.id = ProxId++;
    novoNo->fator_b = 0;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}


// Função para fazer a rotação simples à esquerda
Compra* rotacaoEsquerda(Compra* a) {
    Compra* novaRaiz = a->dir;
    a->dir = novaRaiz->esq;
    novaRaiz->esq = a;
    atualizarAltura(a);
    atualizarAltura(novaRaiz);
    return novaRaiz;
}

// Função para fazer a rotação simples à direita
Compra* rotacaoDireita(Compra* a) {
    Compra* novaRaiz = a->esq;
    a->esq = novaRaiz->dir;
    novaRaiz->dir = a;
    atualizarAltura(a);
    atualizarAltura(novaRaiz);
    return novaRaiz;
}

// Função para fazer a rotação dupla esquerda-direita
Compra* rotacaoEsquerdaDireita(Compra* a) {
    a->esq = rotacaoEsquerda(a->esq);
    return rotacaoDireita(a);
}

// Função para fazer a rotação dupla direita-esquerda
Compra* rotacaoDireitaEsquerda(Compra* a) {
    a->dir = rotacaoDireita(a->dir);
    return rotacaoEsquerda(a);
}

Compra* inserirCompra(Compra* a, DadoCompra dado){
    int num;
	if(a == NULL){
        return criarCompra(dado);
	} else {
		if(dado.id < a->dado.id){
			a->esq = inserirCompra(a->esq, dado);
		}else{
            a->dir = inserirCompra(a->dir, dado);
		}
        int balanceamento = calcula_FB(a);
     // Casos de balanceamento
        if (balanceamento > 1) {
            if (dado.id < a->esq->dado.id)
                return rotacaoDireita(a);
            else
                return rotacaoEsquerdaDireita(a);
        }
        if (balanceamento < -1) {
            if (dado.id > a->dir->dado.id)
                return rotacaoEsquerda(a);
            else
                return rotacaoDireitaEsquerda(a);
        }
        return a;
	}
}


int altura_AVL(Compra* a){
	int alt_esq = 0, alt_dir = 0;
	if(a==NULL)
		return 0;
	else{
		alt_esq = altura_AVL(a->esq);
		alt_dir = altura_AVL(a->dir);

		if(alt_esq > alt_dir)
			return (1+ alt_esq);
		else
			return (1+alt_dir);
	}
}

int fatorBalanceamento(Compra* a) {
    if (a == NULL)
        return 0;
    return (altura_AVL(a->esq) - altura_AVL(a->dir));
}
/*
void percorrerEmOrdem(Compra* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esq);
        printf("ID: %d, Valor: %f", raiz->dado.id, raiz->dado.valor);
        percorrerEmOrdem(raiz->dir);
    }
}*/


void imprime(Compra* a){
    if (a == NULL){
		return;
	}
    printf("%d",a->dado.id);

    if(a->esq != NULL)
        printf("(E:%d)",a->esq->dado.id);
    if(a->dir != NULL)
        printf("(D:%d)",a->dir->dado.id);
    printf("\n");

    imprime(a->esq);
    imprime(a->dir);
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

Uno* buscarNoUsu(int num, Uno *inicio){
    while(inicio != NULL) {
        if(inicio->usuario.cpf == num)
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

Usuario* buscarUsuarioTabela(int num){
    int indice = hashing(num);
    Uno *no = buscarNo(num, tabelaU[indice]->inicio);
    if(no)
        return &no->usuario;
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
