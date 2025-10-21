#include <stdio.h>
#include <locale.h>

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

    setlocale(LC_ALL, "pt_BR.UTF-8");
    setlocale(LC_NUMERIC, "C");


    Carta c1;

    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &c1.estado);

    printf("Código (ex: A01): ");
    scanf(" %4s", c1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c1.cidade);

    printf("População (número inteiro): ");
    scanf("%d", &c1.populacao);

    printf("Área em km² (use ponto, ex: 1521.11): ");
    scanf("%f", &c1.area_km2);

    printf("PIB em bilhões (use ponto, ex: 699.28): ");
    scanf("%f", &c1.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c1.pontos_turisticos);

    Carta c2;

    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &c2.estado);

    printf("Código (ex: A01): ");
    scanf(" %4s", c2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c2.cidade);

    printf("População (número inteiro): ");
    scanf("%d", &c2.populacao);

    printf("Área em km² (use ponto, ex: 1200.25): ");
    scanf("%f", &c2.area_km2);

    printf("PIB em bilhões (use ponto, ex: 300.50): ");
    scanf("%f", &c2.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c2.pontos_turisticos);

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", c1.estado);
    printf("Código: %s\n", c1.codigo);
    printf("Nome da Cidade: %s\n", c1.cidade);
    printf("População: %d\n", c1.populacao);
    printf("Área: %.2f km²\n", c1.area_km2);
    printf("PIB: %.2f bilhões de reais\n", c1.pib_bilhoes);
    printf("Número de Pontos Turísticos: %d\n", c1.pontos_turisticos);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", c2.estado);
    printf("Código: %s\n", c2.codigo);
    printf("Nome da Cidade: %s\n", c2.cidade);
    printf("População: %d\n", c2.populacao);
    printf("Área: %.2f km²\n", c2.area_km2);
    printf("PIB: %.2f bilhões de reais\n", c2.pib_bilhoes);
    printf("Número de Pontos Turísticos: %d\n", c2.pontos_turisticos);

    return 0;
}
