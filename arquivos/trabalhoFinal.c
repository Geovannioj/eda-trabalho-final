#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Municipios {

    char cidade[51];
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

    FILE *entrada,*saida;
    char  UF[3],municipio[50], linha_lida[100], CD[7], EPAO[7], TPD[7], LB[7], TSB[7], ASB[7], APD[7], EPO[7], TOTAL[7];
    int i = 0, j = 0,verifica = 0;
    long int current_line = 0;

    fflush(stdin);

    entrada = fopen("CFO_UF_municipios_brasil.csv","r");
    //saida = fopen("relatorio_municipios.txt","a");
    if(entrada == NULL){
        printf("Problema ao abrir o arquivo, verifique!\n");
        return;
    }
    //fprintf(saida,"UF\tMunicipio\tCD\tEPAO\tTPD\tLB\tTSB\tASB\tAPD\tEPO\tTOTAL\n");


    while(!feof(entrada)){
        current_line++;
        fgets(linha_lida,100,entrada);

        if(current_line == line){
            //Pega_estado
            UF[0] = linha_lida[0];
            UF[1] = linha_lida[1];
            UF[2] = '\0';

            //pega cidade
            i=3;
            j=0;
            while(verifica == 0){

                municipio[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            municipio[j] = '\0';

            verifica = j = 0;
            i++;
            //pega CD - Quantide de cirurgiões dentistas
            while(verifica == 0){
                CD[j++] =linha_lida[i++];

                if(linha_lida[i]==';'){
                    verifica = 1;
                }
            }
            CD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega EPAO - Entidade Prestadora De Assistencia Odontologica
            while(verifica == 0){
                EPAO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            EPAO[j] = '\0';

            //pega TPD - Quantide de Técnicos em Prótese Dentária

            verifica = j = 0;
            i++;

            while(verifica == 0){
                TPD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TPD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega LB - Quantide De Laboratorio De Protese Dentaria
            while(verifica == 0){
                LB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            LB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega TSB - Quantide de Técnicos em Saúde Bucal
            while(verifica == 0){
                TSB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TSB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega ASB - Quantide de Auxiliares em Saúde Bucal
            while(verifica == 0){
                ASB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            ASB[j] = '\0';
            verifica = j = 0;
            i++;

            //pega APD - Quantide de Auxiliares de Próteses Dentárias
            while(verifica == 0){
                APD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            APD[j] = '\0';
            verifica = j = 0;
            i++;

            int continua_leitura = 0;
            //pega EPOs - Quantide de Empresa De Produtos Odontologicos
            while(verifica == 0){
                EPO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'|| linha_lida[i] == '\n'){
                    verifica = 1;
                    if(linha_lida[i] == '\n'){
                        continua_leitura = 1;
                    }

                }
            }
            EPO[j] = '\0';

            verifica = j = 0;
            i++;

            //pega total
            if(continua_leitura == 0){
                while(verifica == 0){
                TOTAL[j++] = linha_lida[i++];

                if(linha_lida[i] == '\n'||linha_lida[i] ==';'){
                    verifica =1;
                }
            }
            TOTAL[j] = '\0';

            }


            // imprime linha

            printf("UF: %s\n",UF);
            printf("Municipio: %s\n",municipio);
            printf("Quantide de cirurgiões dentistas: %s\n",CD);
            printf("Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            printf("Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            printf("Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            printf("Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            printf("Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            printf("Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            printf("Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            printf("Total %s\n",TOTAL);
/*
            fprintf(saida,"UF: %s\n",UF);
            fprintf(saida,"Municipio: %s\n",municipio);
            fprintf(saida,"Quantide de cirurgiões dentistas: %s\n",CD);
            fprintf(saida,"Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            fprintf(saida,"Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            fprintf(saida,"Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            fprintf(saida,"Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            fprintf(saida,"Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            fprintf(saida,"Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            fprintf(saida,"Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            fprintf(saida,"Total %s\n",TOTAL);
*/
            fflush(stdin);

            fclose(entrada);
           // fclose(saida);
    }


        }
    }

void access_archive_search_state(int long line){

    FILE *entrada,*saida;
    char  UF[3],municipio[50], linha_lida[100], CD[7], EPAO[7], TPD[7], LB[7], TSB[7], ASB[7], APD[7], EPO[7], TOTAL[7];
    int i = 0, j = 0,verifica = 0;
    long int current_line = 0;

    fflush(stdin);

    entrada = fopen("CFO_UF_municipios_brasil.csv","r");
    saida = fopen("relatorio_estado.txt","a");
    if(entrada == NULL){
        printf("Problema ao abrir o arquivo, verifique!\n");
        return;
    }
    //fprintf(saida,"UF\tMunicipio\tCD\tEPAO\tTPD\tLB\tTSB\tASB\tAPD\tEPO\tTOTAL\n");


    while(!feof(entrada)){
        current_line++;
        fgets(linha_lida,100,entrada);

        if(current_line == line){
            //Pega_estado
            UF[0] = linha_lida[0];
            UF[1] = linha_lida[1];
            UF[2] = '\0';

            //pega cidade
            i=3;
            j=0;
            while(verifica == 0){

                municipio[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            municipio[j] = '\0';

            verifica = j = 0;
            i++;
            //pega CD - Quantide de cirurgiões dentistas
            while(verifica == 0){
                CD[j++] =linha_lida[i++];

                if(linha_lida[i]==';'){
                    verifica = 1;
                }
            }
            CD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega EPAO - Entidade Prestadora De Assistencia Odontologica
            while(verifica == 0){
                EPAO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            EPAO[j] = '\0';

            //pega TPD - Quantide de Técnicos em Prótese Dentária

            verifica = j = 0;
            i++;

            while(verifica == 0){
                TPD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TPD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega LB - Quantide De Laboratorio De Protese Dentaria
            while(verifica == 0){
                LB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            LB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega TSB - Quantide de Técnicos em Saúde Bucal
            while(verifica == 0){
                TSB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TSB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega ASB - Quantide de Auxiliares em Saúde Bucal
            while(verifica == 0){
                ASB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            ASB[j] = '\0';
            verifica = j = 0;
            i++;

            //pega APD - Quantide de Auxiliares de Próteses Dentárias
            while(verifica == 0){
                APD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            APD[j] = '\0';
            verifica = j = 0;
            i++;

            int continua_leitura = 0;
            //pega EPOs - Quantide de Empresa De Produtos Odontologicos
            while(verifica == 0){
                EPO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'|| linha_lida[i] == '\n'){
                    verifica = 1;
                    if(linha_lida[i] == '\n'){
                        continua_leitura = 1;
                    }

                }
            }
            EPO[j] = '\0';

            verifica = j = 0;
            i++;

            //pega total
            if(continua_leitura == 0){
                while(verifica == 0){
                TOTAL[j++] = linha_lida[i++];

                if(linha_lida[i] == '\n'||linha_lida[i] ==';'){
                    verifica =1;
                }
            }
            TOTAL[j] = '\0';

            }


            // imprime linha
/*
            printf("UF: %s\n",UF);
            printf("Municipio: %s\n",municipio);
            printf("Quantide de cirurgiões dentistas: %s\n",CD);
            printf("Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            printf("Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            printf("Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            printf("Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            printf("Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            printf("Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            printf("Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            printf("Total %s\n",TOTAL);
*/
            fprintf(saida,"UF: %s\n",UF);
            fprintf(saida,"Municipio: %s\n",municipio);
            fprintf(saida,"Quantide de cirurgiões dentistas: %s\n",CD);
            fprintf(saida,"Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            fprintf(saida,"Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            fprintf(saida,"Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            fprintf(saida,"Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            fprintf(saida,"Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            fprintf(saida,"Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            fprintf(saida,"Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            fprintf(saida,"Total %s\n",TOTAL);

            fflush(stdin);

            fclose(entrada);
            fclose(saida);
    }


        }
    }


void access_archive_city(int long line){

    FILE *entrada,*saida;
    char  UF[3],municipio[50], linha_lida[100], CD[7], EPAO[7], TPD[7], LB[7], TSB[7], ASB[7], APD[7], EPO[7], TOTAL[7];
    int i = 0, j = 0,verifica = 0;
    long int current_line = 0;

    fflush(stdin);

    entrada = fopen("CFO_UF_municipios_brasil.csv","r");
    saida = fopen("relatorio_municipios.txt","a");
    if(entrada == NULL){
        printf("Problema ao abrir o arquivo, verifique!\n");
        return;
    }
    //fprintf(saida,"UF\tMunicipio\tCD\tEPAO\tTPD\tLB\tTSB\tASB\tAPD\tEPO\tTOTAL\n");


    while(!feof(entrada)){
        current_line++;
        fgets(linha_lida,100,entrada);

        if(current_line == line){
            //Pega_estado
            UF[0] = linha_lida[0];
            UF[1] = linha_lida[1];
            UF[2] = '\0';

            //pega cidade
            i=3;
            j=0;
            while(verifica == 0){

                municipio[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            municipio[j] = '\0';

            verifica = j = 0;
            i++;
            //pega CD - Quantide de cirurgiões dentistas
            while(verifica == 0){
                CD[j++] =linha_lida[i++];

                if(linha_lida[i]==';'){
                    verifica = 1;
                }
            }
            CD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega EPAO - Entidade Prestadora De Assistencia Odontologica
            while(verifica == 0){
                EPAO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            EPAO[j] = '\0';

            //pega TPD - Quantide de Técnicos em Prótese Dentária

            verifica = j = 0;
            i++;

            while(verifica == 0){
                TPD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TPD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega LB - Quantide De Laboratorio De Protese Dentaria
            while(verifica == 0){
                LB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            LB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega TSB - Quantide de Técnicos em Saúde Bucal
            while(verifica == 0){
                TSB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TSB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega ASB - Quantide de Auxiliares em Saúde Bucal
            while(verifica == 0){
                ASB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            ASB[j] = '\0';
            verifica = j = 0;
            i++;

            //pega APD - Quantide de Auxiliares de Próteses Dentárias
            while(verifica == 0){
                APD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            APD[j] = '\0';
            verifica = j = 0;
            i++;

            int continua_leitura = 0;
            //pega EPOs - Quantide de Empresa De Produtos Odontologicos
            while(verifica == 0){
                EPO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'|| linha_lida[i] == '\n'){
                    verifica = 1;
                    if(linha_lida[i] == '\n'){
                        continua_leitura = 1;
                    }

                }
            }
            EPO[j] = '\0';

            verifica = j = 0;
            i++;

            //pega total
            if(continua_leitura == 0){
                while(verifica == 0){
                TOTAL[j++] = linha_lida[i++];

                if(linha_lida[i] == '\n'||linha_lida[i] ==';'){
                    verifica =1;
                }
            }
            TOTAL[j] = '\0';

            }


            // imprime linha
/*
            printf("UF: %s\n",UF);
            printf("Municipio: %s\n",municipio);
            printf("Quantide de cirurgiões dentistas: %s\n",CD);
            printf("Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            printf("Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            printf("Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            printf("Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            printf("Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            printf("Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            printf("Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            printf("Total %s\n",TOTAL);
*/
            fprintf(saida,"UF: %s\n",UF);
            fprintf(saida,"Municipio: %s\n",municipio);
            fprintf(saida,"Quantide de cirurgiões dentistas: %s\n",CD);
            fprintf(saida,"Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            fprintf(saida,"Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            fprintf(saida,"Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            fprintf(saida,"Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            fprintf(saida,"Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            fprintf(saida,"Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            fprintf(saida,"Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            fprintf(saida,"Total %s\n",TOTAL);

            fflush(stdin);

            fclose(entrada);
            fclose(saida);
    }


        }
    }
void access_ordenated_tree_city(tree *raiz){
    if(raiz->esquerda){
        access_ordenated_tree_city(raiz->esquerda);
    }
    access_archive_city(raiz->node->linha);

    if(raiz->direita){
        access_ordenated_tree_city(raiz->direita);
    }
}

void access_archive_cd(int long line){

    FILE *entrada,*saida;
    char  UF[3],municipio[50], linha_lida[100], CD[7], EPAO[7], TPD[7], LB[7], TSB[7], ASB[7], APD[7], EPO[7], TOTAL[7];
    int i = 0, j = 0,verifica = 0;
    long int current_line = 0;

    fflush(stdin);

    entrada = fopen("CFO_UF_municipios_brasil.csv","r");
    saida = fopen("relatorio_cd.txt","a");
    if(entrada == NULL){
        printf("Problema ao abrir o arquivo, verifique!\n");
        return;
    }
    //fprintf(saida,"UF\tMunicipio\tCD\tEPAO\tTPD\tLB\tTSB\tASB\tAPD\tEPO\tTOTAL\n");


    while(!feof(entrada)){
        current_line++;
        fgets(linha_lida,100,entrada);

        if(current_line == line){
            //Pega_estado
            UF[0] = linha_lida[0];
            UF[1] = linha_lida[1];
            UF[2] = '\0';

            //pega cidade
            i=3;
            j=0;
            while(verifica == 0){

                municipio[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            municipio[j] = '\0';

            verifica = j = 0;
            i++;
            //pega CD - Quantide de cirurgiões dentistas
            while(verifica == 0){
                CD[j++] =linha_lida[i++];

                if(linha_lida[i]==';'){
                    verifica = 1;
                }
            }
            CD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega EPAO - Entidade Prestadora De Assistencia Odontologica
            while(verifica == 0){
                EPAO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            EPAO[j] = '\0';

            //pega TPD - Quantide de Técnicos em Prótese Dentária

            verifica = j = 0;
            i++;

            while(verifica == 0){
                TPD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TPD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega LB - Quantide De Laboratorio De Protese Dentaria
            while(verifica == 0){
                LB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            LB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega TSB - Quantide de Técnicos em Saúde Bucal
            while(verifica == 0){
                TSB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TSB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega ASB - Quantide de Auxiliares em Saúde Bucal
            while(verifica == 0){
                ASB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            ASB[j] = '\0';
            verifica = j = 0;
            i++;

            //pega APD - Quantide de Auxiliares de Próteses Dentárias
            while(verifica == 0){
                APD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            APD[j] = '\0';
            verifica = j = 0;
            i++;

            int continua_leitura = 0;
            //pega EPOs - Quantide de Empresa De Produtos Odontologicos
            while(verifica == 0){
                EPO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'|| linha_lida[i] == '\n'){
                    verifica = 1;
                    if(linha_lida[i] == '\n'){
                        continua_leitura = 1;
                    }

                }
            }
            EPO[j] = '\0';

            verifica = j = 0;
            i++;

            //pega total
            if(continua_leitura == 0){
                while(verifica == 0){
                TOTAL[j++] = linha_lida[i++];

                if(linha_lida[i] == '\n'||linha_lida[i] ==';'){
                    verifica =1;
                }
            }
            TOTAL[j] = '\0';

            }


            // imprime linha
/*
            printf("UF: %s\n",UF);
            printf("Municipio: %s\n",municipio);
            printf("Quantide de cirurgiões dentistas: %s\n",CD);
            printf("Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            printf("Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            printf("Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            printf("Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            printf("Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            printf("Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            printf("Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            printf("Total %s\n",TOTAL);
*/
            fprintf(saida,"UF: %s\n",UF);
            fprintf(saida,"Municipio: %s\n",municipio);
            fprintf(saida,"Quantide de cirurgiões dentistas: %s\n",CD);
            fprintf(saida,"Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            fprintf(saida,"Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            fprintf(saida,"Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            fprintf(saida,"Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            fprintf(saida,"Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            fprintf(saida,"Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            fprintf(saida,"Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            fprintf(saida,"Total %s\n",TOTAL);

            fflush(stdin);

            fclose(entrada);
            fclose(saida);
    }


        }
    }
void access_ordenated_tree_cd(tree *raiz){
    if(raiz->esquerda){
        access_ordenated_tree_cd(raiz->esquerda);
    }
    access_archive_cd(raiz->node->linha);

    if(raiz->direita){
        access_ordenated_tree_cd(raiz->direita);
    }
}

void access_archive_total(int long line){

    FILE *entrada,*saida;
    char  UF[3],municipio[50], linha_lida[100], CD[7], EPAO[7], TPD[7], LB[7], TSB[7], ASB[7], APD[7], EPO[7], TOTAL[7];
    int i = 0, j = 0,verifica = 0;
    long int current_line = 0;

    fflush(stdin);

    entrada = fopen("CFO_UF_municipios_brasil.csv","r");
    saida = fopen("relatorio_total.txt","a");
    if(entrada == NULL){
        printf("Problema ao abrir o arquivo, verifique!\n");
        return;
    }
    //fprintf(saida,"UF\tMunicipio\tCD\tEPAO\tTPD\tLB\tTSB\tASB\tAPD\tEPO\tTOTAL\n");


    while(!feof(entrada)){
        current_line++;
        fgets(linha_lida,100,entrada);

        if(current_line == line){
            //Pega_estado
            UF[0] = linha_lida[0];
            UF[1] = linha_lida[1];
            UF[2] = '\0';

            //pega cidade
            i=3;
            j=0;
            while(verifica == 0){

                municipio[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            municipio[j] = '\0';

            verifica = j = 0;
            i++;
            //pega CD - Quantide de cirurgiões dentistas
            while(verifica == 0){
                CD[j++] =linha_lida[i++];

                if(linha_lida[i]==';'){
                    verifica = 1;
                }
            }
            CD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega EPAO - Entidade Prestadora De Assistencia Odontologica
            while(verifica == 0){
                EPAO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            EPAO[j] = '\0';

            //pega TPD - Quantide de Técnicos em Prótese Dentária

            verifica = j = 0;
            i++;

            while(verifica == 0){
                TPD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TPD[j] = '\0';

            verifica = j = 0;
            i++;

            //pega LB - Quantide De Laboratorio De Protese Dentaria
            while(verifica == 0){
                LB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            LB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega TSB - Quantide de Técnicos em Saúde Bucal
            while(verifica == 0){
                TSB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            TSB[j] = '\0';

            verifica = j = 0;
            i++;

            //pega ASB - Quantide de Auxiliares em Saúde Bucal
            while(verifica == 0){
                ASB[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            ASB[j] = '\0';
            verifica = j = 0;
            i++;

            //pega APD - Quantide de Auxiliares de Próteses Dentárias
            while(verifica == 0){
                APD[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'){
                    verifica = 1;
                }
            }
            APD[j] = '\0';
            verifica = j = 0;
            i++;

            int continua_leitura = 0;
            //pega EPOs - Quantide de Empresa De Produtos Odontologicos
            while(verifica == 0){
                EPO[j++] = linha_lida[i++];

                if(linha_lida[i] == ';'|| linha_lida[i] == '\n'){
                    verifica = 1;
                    if(linha_lida[i] == '\n'){
                        continua_leitura = 1;
                    }

                }
            }
            EPO[j] = '\0';

            verifica = j = 0;
            i++;

            //pega total
            if(continua_leitura == 0){
                while(verifica == 0){
                TOTAL[j++] = linha_lida[i++];

                if(linha_lida[i] == '\n'||linha_lida[i] ==';'){
                    verifica =1;
                }
            }
            TOTAL[j] = '\0';

            }


            // imprime linha
/*
            printf("UF: %s\n",UF);
            printf("Municipio: %s\n",municipio);
            printf("Quantide de cirurgiões dentistas: %s\n",CD);
            printf("Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            printf("Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            printf("Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            printf("Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            printf("Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            printf("Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            printf("Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            printf("Total %s\n",TOTAL);
*/
            fprintf(saida,"UF: %s\n",UF);
            fprintf(saida,"Municipio: %s\n",municipio);
            fprintf(saida,"Quantide de cirurgiões dentistas: %s\n",CD);
            fprintf(saida,"Entidade Prestadora De Assistencia Odontologica: %s\n", EPAO);
            fprintf(saida,"Quantide de Técnicos em Prótese Dentária %s\n",TPD);
            fprintf(saida,"Quantide De Laboratorio De Protese Dentaria %s\n", LB);
            fprintf(saida,"Quantide de Técnicos em Saúde Bucal %s\n",TSB);
            fprintf(saida,"Quantide de Auxiliares em Saúde Bucal %s\n",ASB);
            fprintf(saida,"Quantide de Auxiliares de Próteses Dentárias %s\n",APD);
            fprintf(saida,"Quantide de Empresa De Produtos Odontologicos %s\n",EPO);
            fprintf(saida,"Total %s\n",TOTAL);

            fflush(stdin);

            fclose(entrada);
            fclose(saida);
    }


        }
    }
void access_ordenated_tree_total(tree *raiz){
    if(raiz->esquerda){
        access_ordenated_tree_total(raiz->esquerda);
    }
    access_archive_total(raiz->node->linha);

    if(raiz->direita){
        access_ordenated_tree_total(raiz->direita);
    }
}

void undo_tree(tree *raiz){
    if(raiz->esquerda)
        undo_tree(raiz->esquerda);

    if(raiz->direita)
        undo_tree(raiz->direita);

    free(raiz);
}
void undo_header(header *header){
    undo_tree(header->raiz_total);
    undo_tree(header->raiz_municipio);
    undo_tree(header->raiz_cd);
}
void search_city(tree *raiz, char *municipio) {

    if(strcmp(raiz->node->cidade, municipio) == 0)
	{
        access_archive(raiz->node->linha);

	}else if(raiz->esquerda && strcmp(municipio, raiz->node->cidade) < 0)
    {
		search_city(raiz->esquerda, municipio);

    }else if(raiz->direita && strcmp(municipio, raiz->node->cidade) > 0)
    {
		search_city(raiz->direita, municipio);
    }
}

void search_state(tree *raiz, char *UF){

    if(strcmp(raiz->node->uf,UF) == 0){
        access_archive_search_state(raiz->node->linha);

    }
    if(raiz->esquerda){

        search_state(raiz->esquerda,UF);

    }
    if(raiz->direita){

        search_state(raiz->direita,UF);

    }

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
void add_city_tree(header *raiz, long int linha,char UF[3], char newCity[50]){
    tree * new_city_node = (tree*)malloc(sizeof(tree)); // ponteiro
    //new_city_node = (tree*)malloc(sizeof(tree)); //aloco dinamicamente

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
        }
        else{
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
            add_ordenated_total_tree(raiz->direita,new_node);
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
    }else{
        add_ordenated_total_tree(raiz->raiz_total,new_node);
    }
}


tree *carregar_Arquivo(header *raiz){
    FILE *entrada;
    char UF[3],municipio[50],linha[100], CD_arquivo[7],total_arquivo[7];
    int CD,total,i = 0, j =0,verifica=0,contaColuna=0;
    long int qtde_linha = 0;

      entrada = fopen("CFO_UF_municipios_brasil.csv","r");

        if(entrada == NULL){

            printf("Arquivo com problema, tente novamente!\n");
            return;
        }

        fflush(stdin);
        while(!feof(entrada)){
            //leitura da linha
            fgets(linha,100,entrada);
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

                verifica = j = 0;
                i++;
                //pega CD - Quantide de cirurgiões dentistas
                while(verifica == 0){
                    CD_arquivo[j++] =linha[i++];

                    if(linha[i]==';'){
                        verifica = 1;
                    }
                }
                CD_arquivo[j] = '\0';
                CD = atoi(CD_arquivo);

                verifica = j = 0;
                i++;


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


            verifica = j = 0;
            i++;
/*
            while(verifica == 0){
                total_arquivo[j++] = linha[i++];

                if(linha[i] == '\n'||linha[i] ==';'){
                    verifica =1;
                }
            }
            total_arquivo[j] = '\0';
            total = atoi(total_arquivo);

*/
            do {
                total_arquivo[j++] = linha[i++];
            } while(linha[i] != '\n');
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
    char *cidade = (char*)malloc(sizeof(char)*50);
    //char *UF = (char*)malloc(sizeof(char)*3);
    char UF[3];
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
                        case 1:
                                access_ordenated_tree_city(raiz_trees->raiz_municipio);
                                printf("relatorio gerado no arquivo: relatorio_municipios.txt\n");
                                break;
                        case 2: access_ordenated_tree_cd(raiz_trees->raiz_cd);
                                printf("relatorio gerado no arquivo: relatorio_cd.txt\n");
                                break;
                        case 3: access_ordenated_tree_total(raiz_trees->raiz_total);
                                printf("relatorio gerado no arquivo: relatorio_total.txt\n");
                                break;
                        default:printf("Opcao invalida, escolha uma das opcoes do menu\n");
                    }
                    break;

            case 3: printf("Digite as duas siglas do estado - Ex: \"DF\" : ");
                    scanf("%s",UF);
                    search_state(raiz_trees->raiz_total,UF);
                    printf("Relatorio do estado %s esta no arquivo relatorio_estado.txt\n");
                    break;
            case 4: printf("Digite o municipio em maiusculo para ser procurado:");
                    scanf("%s",cidade);
                    search_city(raiz_trees->raiz_municipio,cidade);
                    break;
            case 5: undo_header(raiz_trees);
                    printf("\nPrograma finalizado\n");
                    break;
            default: printf("Opcao invalida, escolha uma das opcoes do menu!\n");
        }

    }while(opcaoMenuPrincipal != 5);

    return 0;
}
