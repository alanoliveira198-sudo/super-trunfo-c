#include <stdio.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>  // SetConsoleOutputCP / SetConsoleCP
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
    // Garantir UTF-8 no console do Windows (dispensa usar 'chcp 65001' manualmente)
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
    #endif

    // Acentos PT-BR e separador decimal com ponto
    setlocale(LC_ALL, "pt_BR.UTF-8");
    setlocale(LC_NUMERIC, "C");

    Carta c1;

    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c%*[^\n]", &c1.estado);          // lê 1 char e descarta resto da linha

    printf("Código (ex: A01): ");
    scanf(" %4s%*[^\n]", c1.codigo);          // lê até 4 chars e descarta resto

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c1.cidade);              // lê até o fim da linha (com espaços)

    printf("População (número inteiro): ");
    scanf(" %d%*[^\n]", &c1.populacao);

    printf("Área em km² (use ponto, ex: 1521.11): ");
    scanf(" %f%*[^\n]", &c1.area_km2);

    printf("PIB em bilhões (use ponto, ex: 699.28): ");
    scanf(" %f%*[^\n]", &c1.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf(" %d%*[^\n]", &c1.pontos_turisticos);

    Carta c2;

    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c%*[^\n]", &c2.estado);

    printf("Código (ex: A01): ");
    scanf(" %4s%*[^\n]", c2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c2.cidade);

    printf("População (número inteiro): ");
    scanf(" %d%*[^\n]", &c2.populacao);

    printf("Área em km² (use ponto, ex: 1200.25): ");
    scanf(" %f%*[^\n]", &c2.area_km2);

    printf("PIB em bilhões (use ponto, ex: 300.50): ");
    scanf(" %f%*[^\n]", &c2.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf(" %d%*[^\n]", &c2.pontos_turisticos);

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
