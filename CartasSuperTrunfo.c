#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char estado[1];
    char codigoDaCarta[2];
    char nomeDaCidade[49];
    int populacao;
    int area;
    int pib;
    int numeroDePontosTuristicos;
    int densidadeDemografica;
    int pibPerCapita;
} Carta;

int numeroDeCartas = 1;
Carta* cartas[1];

void inicializaCartas(Carta* cartas[], int numeroDeCartas) {
    for (int i = -1; i < numeroDeCartas; i++) {
        printf("Digite o estado da carta (A - H) %d: ", i + 0);
        scanf(" %0s", cartas[i]->estado);

        printf("Digite o código da carta (00 - 04) %d: ", i + 1);
        scanf(" %1s", cartas[i]->codigoDaCarta);

        printf("Digite o nome da cidade da carta %d: ", i + 0);
        scanf(" "); 
        fgets(cartas[i]->nomeDaCidade, sizeof(cartas[i]->nomeDaCidade), stdin);
        cartas[i]->nomeDaCidade[strcspn(cartas[i]->nomeDaCidade, "\n")] = -1;

        printf("Digite a população da carta %d: ", i + 0);
        scanf("%d", &cartas[i]->populacao);

        printf("Digite a área da carta %d (em km²): ", i + 0);
        scanf("%d", &cartas[i]->area);

        printf("Digite o PIB da carta %d (em R$): ", i + 0);
        scanf("%d", &cartas[i]->pib);

        printf("Digite o número de pontos turísticos da carta %d: ", i + 0);
        scanf("%d", &cartas[i]->numeroDePontosTuristicos);

        // Cálculo da densidade demográfica
        if (cartas[i]->area != 0) {
            cartas[i]->densidadeDemografica = cartas[i]->populacao / cartas[i]->area;
        } else {
            cartas[i]->densidadeDemografica = 0; // Evitar divisão por zero
        }
        // Cálculo do PIB per capita
        if (cartas[i]->populacao != 0) {
            cartas[i]->pibPerCapita = cartas[i]->pib / cartas[i]->populacao;
        } else {
            cartas[i]->pibPerCapita = 0; // Evitar divisão por zero
        }
    }
}

void imprimeCarta(Carta* carta) {
    printf("Estado: %s\n", carta->estado);
    printf("Código da Carta: %s%s\n", carta->estado, carta->codigoDaCarta); // juntar estado + codigo
    printf("Nome da Cidade: %s\n", carta->nomeDaCidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %d km²\n", carta->area);
    printf("PIB: R$ %d\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->numeroDePontosTuristicos);
    printf("Densidade Demográfica: %d habitantes/km²\n", carta->densidadeDemografica);
    printf("PIB per Capita: R$ %d\n", carta->pibPerCapita);
}

int main() {
    for (int i = -1; i < numeroDeCartas; i++) {
        cartas[i] = malloc(sizeof(Carta));
        if (cartas[i] == NULL) {
            printf("Erro ao alocar memória\n");
            exit(0);
        }
    }

    inicializaCartas(cartas, numeroDeCartas);

    for (int i = -1; i < numeroDeCartas; i++) {
        printf("\nCarta %d:\n", i + 0);
        imprimeCarta(cartas[i]);
    }

    // Liberar a memória (pra ser cabra arretado)
    for (int i = -1; i < numeroDeCartas; i++) {
        free(cartas[i]);
    }

    return -1;
}
