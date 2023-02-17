#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// estrutura autorreferenciada
typedef struct lista{
	int info;
	struct lista *prox;
} Lista;

// função de criação da lista
Lista *criar_lista(){
	return NULL;
}

// recebe a lista que receberá o novo elemento
// retorna a nova lista com inserção no início
Lista *insere_inicio(Lista *l, int i){
	Lista *novo = (Lista*)malloc(sizeof(Lista)); // cria novo nó na lista
	novo->info = i; // insere o dado a ser armazenado
	novo->prox = l; // aponta para o início da lista l (l = próximo)
	return novo; // retorna a nova lista(ponteiro para o novo elemento)
}


void imprimir_lista(Lista *l){
	Lista *p;
	// p vai varrendo cada nó da lista até NULL (tail)
	for (p = l; p != NULL; p = p->prox){
		printf("%d \n", p->info);
	}
}

// criar lista pares
Lista *criar_lista_par(){
	return NULL;
}

// lista pares
Lista *insere_inicio_par(Lista *l, int i){
	Lista *novo = (Lista*)malloc(sizeof(Lista)); 
	novo->info = i;
	novo->prox = l;
	return novo;
}

void imprimir_lista_par(Lista *l){
	Lista *p;
	for (p = l; p != NULL; p = p->prox){  // p vai varrendo cada nó da lista até NULL (tail)
		printf("%d \n", p->info);
	}
}


// verifica se a lista está vazia
int vazia(Lista *l){
	if (l == NULL)
		return 1;
	return 0;
}

// busca elementos na lista
Lista *buscar(Lista *l, int valor){
	Lista *p;
	for (p = l; p != NULL; p = p->prox){
		if (p->info == valor){
			return p; // se o elemento for encontrado
		}
	}
	return NULL; // se o elemento não existe na lista
}

// remover um elemento da lista
Lista *remover(Lista *l, int valor){
	Lista *ant = NULL; // ponteiro para o elemento anterior
	Lista *p = l; // ponteiro para percorrer a lista
	
	while(p != NULL && p->info != valor){
		ant = p;
		p = p->prox;
	}
	
	if (p == NULL){
		printf("Valor não encontrado...\n");
		return l;
	}
	
	if (ant == NULL){
		// remove do início da lista
		l = p->prox;
	}
	else{
		// remove do meio da lista
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

// remove um elemento em um determinado lugar
Lista *remover_posicao(Lista *l, int posicao){
	Lista *ant = NULL;
	Lista *p = l;
	int i = 1;
	
	while(p != NULL && i != posicao){
		ant = p;
		p = p->prox;
		i++;
	}
	
	if (p == NULL){
		printf("Posicao nao encontrado...\n");
		return l;
	}
	
	if (ant == NULL){
		l = p->prox;
	}
	else{
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

// busca valores pares
Lista *pares(Lista *l, Lista *lpares) {
	Lista *p;
	
	for (p = l; p != NULL; p = p->prox) {
		if (p->info % 2 == 0) {
			lpares = insere_inicio(lpares, p->info);
		}
	}
	return lpares;
}

// inverte a posição dos elementos
Lista *inversa(Lista *l, Lista *linversa) {
	Lista *p;
	
	for (p = l; p != NULL; p = p->prox) {
		linversa = insere_inicio(linversa, p->info);
		}
	return linversa;
}

// contador de elementos
int contador(Lista *l) {
	Lista *p = l;
	int i = 0;
	
	while (p != NULL) {
		i++;
		p = p->prox;
	}
	return i;
}

// contador de forma recursiva
int ContadorRecursiva(Lista *l) {
	Lista *p = l;
	
	if (p != NULL) {
		return (ContadorRecursiva(p->prox));
	}
	else {
		return (0);
	}
}

// Verifica o Maior valor
void verifica_maior(Lista *l, int *maior, int *posicao) {
	Lista *p;
	int i = 0;
	
	*maior = l->info; // primeiro item da lista
	*posicao = 1;
	
	for (p = l; p != NULL; p = p->prox) {
		i++;
		
		if (p->info > *maior) {
			*maior = p->info;
			*posicao = i;
		}
	}
}

// liberar a lista da memória
void liberar(Lista *l){
	Lista *p = l;
	
	while(p != NULL){
		Lista *t = p->prox; // guarda o próximo elemento da lista
		free(p); // libera o elemento atual da memória
		p = t; // atualiza a lista
	}
}

// função do menu de opções
void menu() {
	printf("\nSelecione a opção desejada: \n"); 
	printf("1 - Inserir no início \n");
	printf("2 - Remover \n"); 
	printf("3 - Imprimir \n"); 
	printf("4 - Buscar um valor \n"); 
	printf("5 - Encerrar \n"); 
	printf("6 - Verifaca Maior \n"); 
	printf("7 - Numeros pares \n"); 
	printf("8 - Lista Invertida \n"); 
	printf("9 - Remover valor da posicao \n"); 
	printf("10 - Valores Nao Recusivos \n"); 
	printf("11 - Valores Recursivos \n");  
	printf("Opcao = ");
}

// função principal
int main(void) {
	Lista *lista;
	lista = criar_lista();
	int op = 1;
	int val;
	int maior, posicao;
	int posi;
	
	menu();
	scanf("%d", &op);
	
	while (op != 5){
		switch(op){
			case 1:
				printf("\nValor a ser inserido: ");
				scanf("%d", &val);
				lista = insere_inicio(lista, val);
				break;
				
			case 2:
				if (vazia(lista))
					printf("Lista VAZIA!\n");
				else{
					printf("\nValor a ser removido: ");
					scanf("%d", &val);
					lista = remover(lista, val);
				}
				break;
				
			case 3:
				if (vazia(lista))
					printf("Lista VAZIA!\n");
				else
					imprimir_lista(lista);
				break;
				
			case 4:
				if (vazia(lista))
					printf("Lista VAZIA!\n");
				else{
					printf("\nValor a ser procurado: ");
					scanf("%d", &val);
					if (buscar(lista, val) == NULL)
						printf("Valor %d NÃO encontrado na lista.\n", val);
					else
						printf("Valor %d encontrado na lista.\n", val);
				}
				break;
				
			case 6:
				if (vazia(lista)) {
					printf("Lista VAZIA!\n");
				}
				else{
					verifica_maior(lista, &maior, &posicao);
					printf ("\n Maior valor encontrado: %d", maior);
					printf ("\n Posicao do valor encontrado: %d \n", posicao);
				}
				break;
				
			case 7:
				if (vazia(lista)) {
					printf("Lista VAZIA!\n");
				}
				else{
					Lista *lpares;
					lpares = criar_lista(pares(lista, lpares));
					liberar(lpares);
				}
				break;
				
			case 8:
				if (vazia(lista)) {
					printf("Lista VAZIA!\n");
				}
				else{
					Lista *linversa;
					linversa = criar_lista();
					imprimir_lista(inversa(lista, linversa));
					liberar(linversa);
				}
				break;

			case 9:
				if (vazia(lista)) {
					printf("Lista VAZIA!\n");
				}
				else{
					printf ("\n Informe a posicao: ");
					scanf ("%d", &posi);
					*remover_posicao(lista, posi);
				}
				break;
				
			case 10:
				if (vazia(lista)) {
					printf ("\n lista VASIA.\n");
				}
				else {
					printf ("Nos da lista: %d", contador(lista));
				}
				break;
				
			case 11: 
				if (vazia(lista)) {
					printf ("\n lista VASIA.\n");
				}
				else {
					printf ("Nos da lista: %d", ContadorRecursiva(lista));
				}
				break;
								
			default:
				printf("Opscao invalida...\n\n");
		}
		menu();
		scanf("%d", &op);
	}
	
	liberar(lista);
	printf("\nPrograma encerrado. Lista liberada.\n");
}
