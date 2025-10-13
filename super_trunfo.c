#include <stdio.h>

typedef struct {
    char estado;
    char codigo[5];
    char cidade[50];
    int populacao;
    float area_km2;
    float pib_bilhoes;
    int pontos_turisticos;
} Carta;

int main(void) {
    printf("Estrutura Carta definida.\n");
    return 0;
}
