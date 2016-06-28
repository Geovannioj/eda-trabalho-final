#include<stdio.h>
#include<stdlib.h>

typedef struct Nofinal{
   char UF[2];
   char Municipio[30];
   int EPAOs;
   int TPDs;
   int LBs;
   int ASBs;
   int APDs;
   int EPOs;
   int total;
}Nofinal;

typedef struct NoLeitura{
    int linha;
}Noleitura;

void menuPrincipal(){
    printf("################### MENU ################\n");
    printf("1 - Importar dados\n");
    printf("2 - Gerar relatorios\n");
    printf("3 - Relatorio de um Estado\n");
    printf("4 - Consultar os Dados de Um Municipio\n");
    printf("5 - Sair do Sistema\n");
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
FILE *lerArquivo(){
    FILE *entrada;
    char nomeArquivo[150];
    do{
        printf("Digite o arquivo:");
        scanf("%s",nomeArquivo);
        entrada = fopen(nomeArquivo,"r");
        entrada = fopen("CFO_UF_municipios_brasil.csv","r");

        if(entrada == NULL){

            printf("Arquivo com problema, tente novamente!\n");
        }else{

            return entrada;
        }
    }while(entrada == NULL);

}



int main()
{
    FILE *arquivo;
    int opcaoMenuPrincipal,opcaoSubMenu,continua;

    arquivo = lerArquivo();

    //while(!feof(arquivo)){

    //}

    do{
        opcaoMenuPrincipal = 0;
        menuPrincipal();
        scanf("%d",&opcaoMenuPrincipal);

        switch(opcaoMenuPrincipal){

            case 1:
                    break;
            case 2: opcaoSubMenu = subItemMenuPrincipal();
                    switch(opcaoSubMenu){
                        case 1:
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

    fclose(arquivo);
    return 0;
}
