#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NOME 30
#define MAX_CODIGO 10
#define MAX_SUPERFICIE 15
#define MAX_AVIOES_ESPERA 10
#define MAX_AVIOES_CADASTRADOS 30
#define MAX_PISTAS 6
#define MAX_TIPO 10

/*EQUIPE: Elysa Francyne, Laysa Edwyges, Mirelly Fontes, Sophia Sacramento, Valéria Silva.*/

//struct para avião
typedef struct aviao{
    int idAviao;
    char nome[MAX_NOME];
    char modelo[MAX_NOME];
    char fabricante[MAX_NOME];
    char codigoVoo[MAX_CODIGO];
    int maxPassageiros;
    float velocidadeMax;
}Aviao;

//struct para pista
typedef struct pista{
    int idPista;
    char nome[MAX_NOME];
    float comprimento;
    char superficie[MAX_SUPERFICIE];
    Aviao avioesEspera[MAX_AVIOES_ESPERA];
}Pista;

//struct para aeroporto
typedef struct aeroporto{
    int idAeroporto;
    char nome[MAX_NOME];
    char codigoIATA[MAX_CODIGO];
    char tipo[MAX_TIPO];
    int capAnual;
    Aviao avioesCadastrados[MAX_AVIOES_CADASTRADOS];
    int qtdAvioesCadastrados;
    Pista pistasDisponiveis[MAX_PISTAS];
    int qtdPistasDisponiveis;
}Aeroporto;


void cadastrarAeroporto(Aeroporto *a);
void visualizarAeroporto(Aeroporto *a);

void cadastrarAviao(Aeroporto *a);
void listarAvioes(Aeroporto *a);
void recuperarAviaoPorID(Aeroporto *a);
void atualizarAviao(Aeroporto *a);
void removerAviao(Aeroporto *a);


void cadastrarAeroporto(Aeroporto *a){
    printf("Digite o ID do Aeroporto: ");
    scanf("%d", &a->idAeroporto);
    getchar();

    printf("Digite o nome do Aeroporto: ");
    fgets(a->nome, sizeof(a->nome), stdin);
    a->nome[strcspn(a->nome, "\n")] = '\0';

    printf("Digite o codigo IATA: ");
    fgets(a->codigoIATA, sizeof(a->codigoIATA), stdin);
    a->codigoIATA[strcspn(a->codigoIATA, "\n")] = '\0';

    printf("Digite o tipo (publico ou privado): ");
    fgets(a->tipo, sizeof(a->tipo), stdin);
    a->tipo[strcspn(a->tipo, "\n")] = '\0';

    printf("Digite a capacidade de passageiros anual: ");
    scanf("%d", &a->capAnual);
    getchar();

}

void visualizarAeroporto(Aeroporto *a){
    printf("\n=====INFORMACOES DO AEROPORTO=====\n");
    printf("ID: %d\n", a->idAeroporto);
    printf("Nome: %s\n", a->nome);
    printf("Codigo IATA: %s\n", a->codigoIATA);
    printf("Tipo: %s\n", a->tipo);
    printf("Capacidade de passageiros anual: %d\n", a->capAnual);

    if (a->qtdAvioesCadastrados == 0) {
        printf("Nenhum aviao cadastrado.\n");
    } else {
        printf("Avioes cadastrados:\n");
        for (int i = 0; i < a->qtdAvioesCadastrados; i++) {
            printf("%d - %s\n", i + 1, a->avioesCadastrados[i].nome);
        }
    }
    if (a->qtdPistasDisponiveis == 0) {
        printf("Nenhuma pista disponivel.\n");
    } else {
        printf("Pistas disponiveis:\n");
        for (int i = 0; i < a->qtdPistasDisponiveis; i++) {
            printf("  %d - %s\n", i + 1, a->pistasDisponiveis[i].nome);
        }
    }
    printf("====================================\n");
}


void cadastrarAviao(Aeroporto *a){
    if(a->qtdAvioesCadastrados >= MAX_AVIOES_CADASTRADOS){
        printf("Limite de avioes cadastrados atingido.\n");
        return;
    }

    Aviao *av = &a->avioesCadastrados[a->qtdAvioesCadastrados];

    printf("Digite o ID do Aviao: ");
    scanf("%d", &av->idAviao);
    getchar();

    printf("Digite o nome do Aviao: ");
    fgets(av->nome, sizeof(av->nome), stdin);
    av->nome[strcspn(av->nome, "\n")] = '\0';

    printf("Digite o modelo do Aviao: ");
    fgets(av->modelo, sizeof(av->modelo), stdin);
    av->modelo[strcspn(av->modelo, "\n")] = '\0';

    printf("Digite o fabricante do Aviao: ");
    fgets(av->fabricante, sizeof(av->fabricante), stdin);
    av->fabricante[strcspn(av->fabricante, "\n")] = '\0';

    printf("Digite o codigo do voo: ");
    fgets(av->codigoVoo, sizeof(av->codigoVoo), stdin);
    av->codigoVoo[strcspn(av->codigoVoo, "\n")] = '\0';

    printf("Digite a quantidade maxima de passageiros: ");
    scanf("%d", &av->maxPassageiros);
    getchar();

    printf("Digite a velocidade maxima (km/h): ");
    scanf("%f", &av->velocidadeMax);
    getchar();

    a->qtdAvioesCadastrados++;
    printf("Aviao cadastrado com sucesso!\n");
    a->qtdAvioesCadastrados = 0;
    a->qtdPistasDisponiveis = 0;

}

void listarAvioes(Aeroporto *a){
    if(a->qtdAvioesCadastrados == 0){
        printf("Nenhum aviao cadastrado.\n");
        return;
    }

    printf("\n=====LISTA DE AVIOES=====\n");
    for(int i = 0; i < a->qtdAvioesCadastrados; i++){
        Aviao *av = &a->avioesCadastrados[i];
        printf("ID: %d\n", av->idAviao);
        printf("Nome: %s\n", av->nome);
        printf("Modelo: %s\n", av->modelo);
        printf("Fabricante: %s\n", av->fabricante);
        printf("Codigo do Voo: %s\n", av->codigoVoo);
        printf("Maximo de Passageiros: %d\n", av->maxPassageiros);
        printf("Velocidade Maxima: %.2f km/h\n", av->velocidadeMax);
        printf("------------------------------\n");
    }
}

void recuperarAviaoPorID(Aeroporto *a){
    if(a->qtdAvioesCadastrados == 0){
        printf("Nenhum aviao cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do Aviao que deseja buscar: ");
    scanf("%d", &id);
    getchar();

    for(int i = 0; i < a->qtdAvioesCadastrados; i++){
        if(a->avioesCadastrados[i].idAviao == id){
            Aviao *av = &a->avioesCadastrados[i];
            printf("\n=====AVIAO ENCONTRADO=====\n");
            printf("ID: %d\n", av->idAviao);
            printf("Nome: %s\n", av->nome);
            printf("Modelo: %s\n", av->modelo);
            printf("Fabricante: %s\n", av->fabricante);
            printf("Codigo do Voo: %s\n", av->codigoVoo);
            printf("Maximo de Passageiros: %d\n", av->maxPassageiros);
            printf("Velocidade Maxima: %.2f km/h\n", av->velocidadeMax);
            printf("===========================\n");
            return;
        }
    }
    printf("Aviao com ID %d nao encontrado.\n", id);
}

void atualizarAviao(Aeroporto *a){
    if(a->qtdAvioesCadastrados == 0){
        printf("Nenhum aviao cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do Aviao que deseja atualizar: ");
    scanf("%d", &id);
    getchar();

    for(int i = 0; i < a->qtdAvioesCadastrados; i++){
        if(a->avioesCadastrados[i].idAviao == id){
            Aviao *av = &a->avioesCadastrados[i];

            printf("Digite o novo nome do Aviao: ");
            fgets(av->nome, sizeof(av->nome), stdin);
            av->nome[strcspn(av->nome, "\n")] = '\0';

            printf("Digite o novo modelo do Aviao: ");
            fgets(av->modelo, sizeof(av->modelo), stdin);
            av->modelo[strcspn(av->modelo, "\n")] = '\0';

            printf("Digite o novo fabricante do Aviao: ");
            fgets(av->fabricante, sizeof(av->fabricante), stdin);
            av->fabricante[strcspn(av->fabricante, "\n")] = '\0';

            printf("Digite o novo codigo do voo: ");
            fgets(av->codigoVoo, sizeof(av->codigoVoo), stdin);
            av->codigoVoo[strcspn(av->codigoVoo, "\n")] = '\0';

            printf("Digite a nova quantidade maxima de passageiros: ");
            scanf("%d", &av->maxPassageiros);
            getchar();

            printf("Digite a nova velocidade maxima (km/h): ");
            scanf("%f", &av->velocidadeMax);
            getchar();

            printf("Aviao atualizado com sucesso!\n");
            return;
        }
    }
    printf("Aviao com ID %d nao encontrado.\n", id);
}

void removerAviao(Aeroporto *a){
    if(a->qtdAvioesCadastrados == 0){
        printf("Nenhum aviao cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do Aviao que deseja remover: ");
    scanf("%d", &id);
    getchar();

    for(int i = 0; i < a->qtdAvioesCadastrados; i++){
        if(a->avioesCadastrados[i].idAviao == id){
            for(int j = i; j < a->qtdAvioesCadastrados - 1; j++){
                a->avioesCadastrados[j] = a->avioesCadastrados[j + 1];
            }
            a->qtdAvioesCadastrados--;
            printf("Aviao removido com sucesso!\n");
            return;
        }
    }
    printf("Aviao com ID %d nao encontrado.\n", id);
}

void menuAvioes(Aeroporto *a){
    int opcao;
    do{
        printf("\n=====MENU AVIOES=====\n");
        printf("1. Cadastrar Aviao\n");
        printf("2. Listar Todos os Avioes\n");
        printf("3. Recuperar Aviao por ID\n");
        printf("4. Atualizar Aviao\n");
        printf("5. Remover Aviao\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1: cadastrarAviao(a); break;
            case 2: listarAvioes(a); break;
            case 3: recuperarAviaoPorID(a); break;
            case 4: atualizarAviao(a); break;
            case 5: removerAviao(a); break;
            case 0: printf("Voltando...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    }while(opcao != 0);
}

