#include <stdio.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

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
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
    #endif

    setlocale(LC_ALL, "pt_BR.UTF-8");
    setlocale(LC_NUMERIC, "C");

    Carta c1, c2;

    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado: ");
    scanf(" %c%*[^\n]", &c1.estado);

    printf("Código: ");
    scanf(" %4s%*[^\n]", c1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c1.cidade);

    printf("População: ");
    scanf(" %d%*[^\n]", &c1.populacao);

    printf("Área em km²: ");
    scanf(" %f%*[^\n]", &c1.area_km2);

    printf("PIB em bilhões: ");
    scanf(" %f%*[^\n]", &c1.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf(" %d%*[^\n]", &c1.pontos_turisticos);

    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado: ");
    scanf(" %c%*[^\n]", &c2.estado);

    printf("Código: ");
    scanf(" %4s%*[^\n]", c2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c2.cidade);

    printf("População: ");
    scanf(" %d%*[^\n]", &c2.populacao);

    printf("Área em km²: ");
    scanf(" %f%*[^\n]", &c2.area_km2);

    printf("PIB em bilhões: ");
    scanf(" %f%*[^\n]", &c2.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf(" %d%*[^\n]", &c2.pontos_turisticos);

    float densidade1 = (float)c1.populacao / c1.area_km2;
    float pib_per_capita1 = (c1.pib_bilhoes * 1000000000.0f) / (float)c1.populacao;

    float densidade2 = (float)c2.populacao / c2.area_km2;
    float pib_per_capita2 = (c2.pib_bilhoes * 1000000000.0f) / (float)c2.populacao;

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", c1.estado);
    printf("Código: %s\n", c1.codigo);
    printf("Nome da Cidade: %s\n", c1.cidade);
    printf("População: %d\n", c1.populacao);
    printf("Área: %.2f km²\n", c1.area_km2);
    printf("PIB: %.2f bilhões de reais\n", c1.pib_bilhoes);
    printf("Número de Pontos Turísticos: %d\n", c1.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", c2.estado);
    printf("Código: %s\n", c2.codigo);
    printf("Nome da Cidade: %s\n", c2.cidade);
    printf("População: %d\n", c2.populacao);
    printf("Área: %.2f km²\n", c2.area_km2);
    printf("PIB: %.2f bilhões de reais\n", c2.pib_bilhoes);
    printf("Número de Pontos Turísticos: %d\n", c2.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);

    return 0;
}
