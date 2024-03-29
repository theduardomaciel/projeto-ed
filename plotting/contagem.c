#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct node{
    int valor;
    struct node *next;
};

struct arvore{
    int valor;
    struct arvore *left;
    struct arvore *right;
};

struct node *create_node(int valor){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->valor = valor;
    newnode->next = NULL;
    
    return newnode;
}


struct arvore *create_arvore(int valor){
    struct arvore *newarvore = (struct arvore*) malloc(sizeof(struct arvore));
    newarvore->valor = valor;
    newarvore->left = NULL;
    newarvore->right = NULL;
    
    return newarvore;
}
//função recursiva para inserir um valor na arvore binária
struct arvore *inserirArvore(struct arvore *arvore,int valor){
    if(arvore==NULL){
        return create_arvore(valor);
    }
    if (valor < arvore->valor) {
        arvore->left = inserirArvore(arvore->left, valor);
    } else if (valor > arvore->valor) {
        arvore->right = inserirArvore(arvore->right, valor);
    }
    return arvore;
    
}
//função para inserir valor na lista encadeada
struct node *inserirLista(struct node *node,int valor){
    if(node==NULL){
        node = create_node(valor);
    }else{
        struct node *newnode = create_node(valor);
        newnode->next = node;
        node = newnode;
        
    }
    return node;
    
}
//função que retorna um número aleatório
int giveRandom(int min, int max) { 
    int num = (rand() % (max - min + 1)) + min; 
    return num;
} 
//função que verifica se um número aleatório já foi sorteado
int jaFoi(int array[],int random_num, int index_array_randoms){
    int i=0;
    while(i<=index_array_randoms){
        if(random_num == array[i]){
            return 1;
        }
        i++;
    }
    return 0;
}
//função que verifica se um número aleatório já foi sorteado na matriz
int jaFoiMatriz(int matriz[][3],int random_num, int index_matriz_search){
    int i=0;
    while(i<=index_matriz_search){
        if(random_num == matriz[i][0]){
            return 1;
        }
        i++;
    }
    return 0;
}
//imprime a arvore binária em ordem
void printArvoreEmOrdem(struct arvore *arvore) {
    if (arvore != NULL) {
        printArvoreEmOrdem(arvore->left);
        printf("%d ", arvore->valor);
        printArvoreEmOrdem(arvore->right);
    }
}
//imprime a lista encadeada
void printLista(struct node *node){
    struct node *aux = node;
    while(aux!=NULL){
        printf("%d ",aux->valor);
        aux = aux->next;
    }
}
//imprime o array de números aleatórios
void printRandoms(int array[],int index_array_randoms){
    int i=0;
    while(i<index_array_randoms){
        printf("%d ",array[i]);
        i++;
    }
}
//função que busca um valor na lista encadeada e retorna a quantidade de comparações realizadas
int buscaLista(struct node *node,int valor){
    struct node *aux = node;
    int comparacoes=0;
    while(aux!=NULL){
        comparacoes++;
        if(aux->valor == valor){
            return comparacoes;
        }
        aux = aux->next;
    }
}
//função recursiva que busca um valor na arvore binária e incrementa a quantidade de comparações realizadas
int buscaArvore(struct arvore *arvore,int valor,int *comp_arvore){
    if(arvore==NULL){
        return -1;
    }else{
        (*comp_arvore)++;
        if(arvore->valor == valor){
            return *comp_arvore;
        }else{
            if(arvore->valor > valor){
                return buscaArvore(arvore->left,valor,comp_arvore);
            }else if(arvore->valor < valor){
                return buscaArvore(arvore->right,valor,comp_arvore);
            }
            
        }
        
    }
}
//imprime a matriz de inteiros
void printMatriz(int matriz[][3],int index_matriz_search){
    int i=0;
    while(i<index_matriz_search){
        printf("[%d,%d,%d]\n",matriz[i][0],matriz[i][1],matriz[i][2]);
        i++;
    }
}
//função que insere os dados da matriz de inteiros para a matriz de strings
void colocar(char matrizz[][20], int matriz[][3],int index_matriz_search, int *index_matriz_colocar){
    int i=0;
    while(i<index_matriz_search){
        sprintf(matrizz[i],"%d %d %d",matriz[i][0],matriz[i][1],matriz[i][2]);
        (*index_matriz_colocar)++;
        i++;
    }
}
//imprime a matriz de strings
void printMatrizColocar(char matrizz[][20],int index_matriz_colocar){
    int i=0;
    while(i<index_matriz_colocar){
        printf("%s\n",matrizz[i]);
        i++;
    }
}
//função recursiva que cria a arvore binária baseado no array dado e retorna essa arvore
struct arvore* construirArvore(int array[], int inicio, int fim) {
    if (inicio > fim)
        return NULL;

    int meio = (inicio + fim) / 2;

    struct arvore* arvore = create_arvore(array[meio]);

    arvore->left = construirArvore(array, inicio, meio - 1);
    arvore->right = construirArvore(array, meio + 1, fim);

    return arvore;
}

int main()
{
    struct node *lista_encadeada = NULL;
    struct arvore *arvore_bi = NULL;      //inicialização das estruturas
    srand(time(0)); //usando a função time(0) para gerar números aleatórios diferentes
    int quant_num=100001;
    int *array_randoms = malloc(quant_num * sizeof(int)); //alocação dinámica de memória do array para aumentar a capacidade
    if (array_randoms == NULL) {
        printf("Erro ao alocar memória.\n");
        return EXIT_FAILURE;
    }
    int index_array_randoms = 0;
    int y=0;
    while(y<quant_num){
        
        array_randoms[y]=y; //o array recebe os valores de 0 até 100.000
        y++;
    }
    printf("Array de Numeros randomizados:\n");
    //printRandoms(array_randoms,y);
    printf("\n");
    
    y = y-1;
    while(y>=0){
        lista_encadeada = inserirLista(lista_encadeada,array_randoms[y]); //insere os valores do array na lista encadeada de forma decrescente
        y--;
    }
    
    arvore_bi = construirArvore(array_randoms,0,quant_num-1); //constroi a arovre binária passando o array como parâmetro
    
    printf("Lista Encadeada:\n");
    //printLista(lista_encadeada);
    printf("\n");
    printf("Arvore em Ordem:\n");
    struct arvore *auxarvore = arvore_bi;
    //printArvoreEmOrdem(auxarvore);
    printf("\n");
    
    int quant_search = 50000; //quantidade de números que serão buscados
    
    int matriz[50000][3]; //matriz que armazenará: número sorteado / comparações na lista / comparações na árvore
    int index_matriz_search = 0;
    
    while(quant_search>0){
        
        int random_num = giveRandom(0,100000); //gera um número aleatório entre 0 e 100.000
        if(jaFoiMatriz(matriz,random_num,index_matriz_search)){ //verifica se esse número já foi sorteado anteriormente
            quant_search++;
        }else{
            int comp_arvore=0;
            int comparacoesLista = buscaLista(lista_encadeada,random_num);  
            struct arvore *aux_arvore = arvore_bi;                           //cria inteiros que armazenarão a quantidade de comparações em cada estrutura
            buscaArvore(aux_arvore,random_num,&comp_arvore);
            int comparacoesArvore=comp_arvore;
            matriz[index_matriz_search][0]=random_num;
            matriz[index_matriz_search][1]=comparacoesLista;     //passa o número aleatório gerado e a quantidade de comparações nas estruturas para a matriz
            matriz[index_matriz_search][2]=comparacoesArvore;
            index_matriz_search++;
        }
        quant_search--;
    }
    
    free(array_randoms); 
    char matrizz[50000][20];  //matriz de strings que receberá a matriz de inteiros para colocar no .txt
    int index_matriz_colocar=0;
    
    colocar(matrizz,matriz,index_matriz_search,&index_matriz_colocar); //a matriz de strings recebe os valores da matriz de inteiros
    //printf("\n\n\n");
    //printMatrizColocar(matrizz,index_matriz_colocar);
    printf("\n\n\n");

    FILE *fPtr;
    fPtr = fopen("data/file1.txt", "w"); //cria o arquivo de texto file1.txt no caminho especificado
    
    if(fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    
    int i=0;
    while(i<index_matriz_search){ //loop que adiciona cada lacuna da matriz no .txt
        fputs(matrizz[i], fPtr);
        fputs("\n", fPtr);
        i++;
    }
    
    fclose(fPtr);
    
    memset(matrizz,'\0',50000);
    memset(matriz,0,50000);

    return 0;
}
