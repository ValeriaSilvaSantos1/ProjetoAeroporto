#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*EQUIPE: Elysa Francyne, Laysa Edwyges, Mirelly Fontes, Sophia Sacramento, Valéria Silva.*/

//struct para avião
typedef struct aviao{
    int idAviao;
    char nome[30];
    char modelo[15];
    char fabricante[15];
    char codigoVoo[10];
    int maxPassageiros;
    float velocidadeMax;
}Aviao;

//struct para pista
typedef struct pista{
    int idPista;
    char nome[30];
    float comprimento;
    char superficie[15];
    Aviao avioesEspera[10];
}Pista;

//struct para aeroporto
typedef struct aeroporto{
    int idAeroporto;
    char nome[30];
    char codigoIATA[3];
    char tipo[10];
    int capAnual;
    Aviao avioesCadastrados[25];
    Pista pistasDisponiveis[5];
}Aeroporto;
