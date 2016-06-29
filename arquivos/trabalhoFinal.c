#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Municipios {

    char cidade[60];
    char uf[3];
    int cd;
    int total;
    long int linha;
} Municipios;

typedef struct tree {

    struct Municipios *node;
    struct tree *esquerda;
    struct tree *direita;
} tree;

typedef struct header {

    tree *raiz_municipio;
    tree *raiz_cd;
    tree *raiz_total;
} header;

void menuPrincipal(){
    printf("################### MENU ################\n");
    printf("1 - Importar dados\n");
    printf("2 - Gerar relatorios\n");
    printf("3 - Relatorio de um Estado\n");
    printf("4 - Consultar os Dados de Um Municipio\n");
    printf("5 - Sair do Sistema\n");
}

void access_archive(int long line){

}

int subItemMenuPrincipal(){
    printf("################### MENU ################\n");
    printf("\tRelatorio ordenado por:\n");
    printf("1 - Municipio\n");
    printf("2 - CD\n");
    printf("3 - Total\n");
    int opcao;
    scanf("%d",&opcao);
    return opcao;
}

void add_ordenated_city_tree (tree *raiz, tree *new_node){
    if(strcmp(new_node->node->cidade, raiz->node->cidade)<=0){
        if(raiz->esquerda == NULL){
            raiz->esquerda = new_node;
        }else{
            add_ordenated_city_tree(raiz->esquerda,new_node);
        }
    }else if(strcmp(new_node->node->cidade, raiz->node->cidade)>0){

        if(raiz->direita ==NULL){
            raiz->direita = new_node;
        }else{
            add_ordenated_city_tree(raiz->direita,new_node);
        }
    }


}
void add_city_tree(header *raiz, long int linha,char UF[3], char newCity[60]){
    tree * new_city_node; // ponteiro
    new_city_node = (tree*)malloc(sizeof(tree)); //aloco dinamicamente
    new_city_node->node = (Municipios*)malloc(sizeof(Municipios));
    strcpy(new_city_node->node->cidade,newCity); // insiro o nome da cidade no novo nó

    new_city_node->node->linha = linha; //insiro a linha no novo nó

    strcpy(new_city_node->node->uf,UF); //insiro o estado(UF) no novo no

    new_city_node->esquerda = NULL; // aponto pra null
    new_city_node->direita = NULL;//aponto pra null

    if(raiz->raiz_municipio == NULL){
        raiz->raiz_municipio = new_city_node;
    }else{
        add_ordenated_city_tree(raiz->raiz_municipio,new_city_node);
    }

}

void add_ordenated_CD_tree(tree *raiz, tree *new_node){
    if(new_node->node->cd <= raiz->node->cd){
        if(raiz->esquerda == NULL){
            raiz->esquerda = new_node;
        }else{
            add_ordenated_CD_tree(raiz->esquerda,new_node);
        }
    }else if( new_node->node->cd > raiz->node->cd){
        if(raiz->direita == NULL){
            raiz->direita = new_node;
        }else{
            add_ordenated_CD_tree(raiz->direita,new_node);
        }
    }

}
void add_CD_tree(header *raiz, char UF[3],int new_CD, long int linha){
    tree *new_node;
    new_node = (tree*)malloc(sizeof(tree));
    new_node->node = (Municipios*)malloc(sizeof(Municipios));
    new_node->node->cd = new_CD;
    new_node->node->linha = linha;
    strcpy(new_node->node->uf,UF);
    new_node->direita = NULL;
    new_node->esquerda =NULL;

    if(raiz->raiz_cd == NULL){
        raiz->raiz_cd = new_node;
    }else{
        add_ordenated_CD_tree(raiz->raiz_cd,new_node);
    }


}

void add_ordenated_total_tree(tree *raiz,tree *new_node){
    if(new_node->node->total <= raiz->node->total){
        if(raiz->esquerda == NULL){
            raiz->esquerda = new_node;
        }else{
            add_ordenated_total_tree(raiz->esquerda,new_node);
        }
    }else if(new_node->node->total > raiz->node->total){
        if(raiz->direita == NULL){
            raiz->direita = new_node;
        }else{
            add_ordenated_total_tree(raiz,new_node);
        }
    }

}
void add_total_tree(header *raiz, char UF[3],int total, long int linha){
    tree *new_node;
    new_node = (tree*)malloc(sizeof(tree));
    new_node->node = (Municipios*)malloc(sizeof(Municipios));
    new_node->node->total = total;
    new_node->node->linha = linha;
    strcpy(new_node->node->uf,UF);
    new_node->direita = NULL;
    new_node->esquerda = NULL;

    if(raiz->raiz_total == NULL){
        raiz->raiz_total = new_node;
    }
}

tree *carregar_Arquivo(header *raiz){
    FILE *entrada;
    char UF[3],municipio[60],linha[100], CD_arquivo[7],total_arquivo[7];
    int CD,total,i = 0, j =0,verifica=0,contaColuna;
    long int qtde_linha = 0;

      entrada = fopen("CFO_UF_municipios_brasil.csv","r+");

        if(entrada == NULL){

            printf("Arquivo com problema, tente novamente!\n");
        }

        fflush(stdin);
        while(!feof(entrada)){
            //leitura da linha

            fgets(linha,150,entrada);
            qtde_linha++;

            //atribuição UF
            UF[0] = linha[0];
            UF[1] = linha[1];
            UF[2] = '\0';

            i = 3;
            j = 0;
            //atribuição municipio
            while(verifica == 0){
                municipio[j++] = linha[i++];

                if(linha[i] == ';'){
                    verifica = 1;
                }
            }
            municipio[j] = '\0';

            i++;
            j = 0;
            verifica = 0;

            while(verifica == 0){
                CD_arquivo[j++] = linha[i++];
                if(linha[i] == ';'){
                    verifica = 1;
                }
            }
            CD_arquivo[j] = '\0';
            CD = atoi(CD_arquivo);

            j=0;
            // procura pelo total
            // necessário pois há linhas que não estão completamente preenchidas
            do{
                i++;
                if(linha[i] == ';')
                    contaColuna++;
                //se for o final da linha coluna total não está preenchida
                if(linha[i] == '\n') {
                    do {
                        i--;
                    } while(linha[i] != ';');
                    i++;
                    break;
                }
                // número de colunas separadas por ';' máximas para chegar em total
                if(contaColuna == 7) {
                    i++;
                    break;
                }
            }while(linha[i] != ';' && linha[i] != '\n');

            j = 0;
            verifica = 0;
            //atribuição do total
            while(verifica == 0){
                total_arquivo[j] = linha[i++];
                if(linha[i] == '/0');
                {
                    verifica = 1;
                }
            }
            total_arquivo[j] = '\0';
            total = atoi(total_arquivo);

            //funções para inserir nas árvores
            add_city_tree(raiz,qtde_linha,UF,municipio); //arvore ordenada por cidades
            add_CD_tree(raiz,UF,CD,qtde_linha);
            add_total_tree(raiz,UF,total,qtde_linha);

            }
            fclose(entrada);
            printf("Operação efetuada com sucesso!\n");
          }


int main()
{
    FILE *arquivo;
    int opcaoMenuPrincipal,opcaoSubMenu,continua;
    header *raiz_trees = (header*)malloc(sizeof(header));

    raiz_trees->raiz_cd = NULL;
    raiz_trees->raiz_municipio = NULL;
    raiz_trees->raiz_total = NULL;



    do{
        opcaoMenuPrincipal = 0;
        menuPrincipal();
        scanf("%d",&opcaoMenuPrincipal);

        switch(opcaoMenuPrincipal){

            case 1:
                    carregar_Arquivo(raiz_trees);
                    break;
            case 2: opcaoSubMenu = subItemMenuPrincipal();
                    switch(opcaoSubMenu){
                        case 1: printf("entrou no switch\n");
                                carregar_Arquivo(raiz_trees);
                                printf("Saiu da funcao\n");
                                break;
                        case 2:
                                break;
                        case 3:
                                break;
                    }
                    break;
            case 3:
                    break;
            case 4:
                    break;
            case 5:
                    break;
        }

    }while(opcaoMenuPrincipal != 5);

    return 0;
}
