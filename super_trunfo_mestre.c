#include <stdio.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

typedef struct {
    char estado;
    char codigo[5];
    char cidade[50];
    unsigned long int populacao;
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
    scanf(" %lu%*[^\n]", &c1.populacao);

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
    scanf(" %lu%*[^\n]", &c2.populacao);

    printf("Área em km²: ");
    scanf(" %f%*[^\n]", &c2.area_km2);

    printf("PIB em bilhões: ");
    scanf(" %f%*[^\n]", &c2.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf(" %d%*[^\n]", &c2.pontos_turisticos);

    double dens1_d = (double)c1.populacao / (double)c1.area_km2;
    double dens2_d = (double)c2.populacao / (double)c2.area_km2;
    float dens1 = (float)dens1_d;
    float dens2 = (float)dens2_d;

    const double BILHAO = 1000000000.0;
    double pib1_reais = (double)c1.pib_bilhoes * BILHAO;
    double pib2_reais = (double)c2.pib_bilhoes * BILHAO;
    double pibpc1_d = pib1_reais / (double)c1.populacao;
    double pibpc2_d = pib2_reais / (double)c2.populacao;
    float pibpc1 = (float)pibpc1_d;
    float pibpc2 = (float)pibpc2_d;

    double invdens1_d = 1.0 / dens1_d;
    double invdens2_d = 1.0 / dens2_d;

    double super1_D = (double)c1.populacao
                    + (double)c1.area_km2
                    + pib1_reais
                    + (double)c1.pontos_turisticos
                    + pibpc1_d
                    + invdens1_d;

    double super2_D = (double)c2.populacao
                    + (double)c2.area_km2
                    + pib2_reais
                    + (double)c2.pontos_turisticos
                    + pibpc2_d
                    + invdens2_d;

    float super1 = (float)super1_D;
    float super2 = (float)super2_D;

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", c1.estado);
    printf("Código: %s\n", c1.codigo);
    printf("Nome da Cidade: %s\n", c1.cidade);
    printf("População: %lu\n", c1.populacao);
    printf("Área: %.2f km²\n", c1.area_km2);
    printf("PIB: %.2f bilhões de reais\n", c1.pib_bilhoes);
    printf("Número de Pontos Turísticos: %d\n", c1.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", dens1);
    printf("PIB per Capita: %.2f reais\n", pibpc1);
    printf("Super Poder: %.2f\n", super1_D);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", c2.estado);
    printf("Código: %s\n", c2.codigo);
    printf("Nome da Cidade: %s\n", c2.cidade);
    printf("População: %lu\n", c2.populacao);
    printf("Área: %.2f km²\n", c2.area_km2);
    printf("PIB: %.2f bilhões de reais\n", c2.pib_bilhoes);
    printf("Número de Pontos Turísticos: %d\n", c2.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", dens2);
    printf("PIB per Capita: %.2f reais\n", pibpc2);
    printf("Super Poder: %.2f\n", super2_D);

    int rPop      = (c1.populacao        > c2.populacao);
    int rArea     = (c1.area_km2         > c2.area_km2);
    int rPIB      = (c1.pib_bilhoes      > c2.pib_bilhoes);
    int rPontos   = (c1.pontos_turisticos> c2.pontos_turisticos);
    int rDens     = (dens1               < dens2);
    int rPibPc    = (pibpc1              > pibpc2);
    int rSuper    = (super1_D            > super2_D);

    printf("\nComparação de Cartas:\n");
    printf("População: %s (%d)\n",         rPop   ? "Carta 1 venceu" : "Carta 2 venceu", rPop);
    printf("Área: %s (%d)\n",               rArea  ? "Carta 1 venceu" : "Carta 2 venceu", rArea);
    printf("PIB: %s (%d)\n",                rPIB   ? "Carta 1 venceu" : "Carta 2 venceu", rPIB);
    printf("Pontos Turísticos: %s (%d)\n",  rPontos? "Carta 1 venceu" : "Carta 2 venceu", rPontos);
    printf("Densidade Populacional: %s (%d)\n", rDens ? "Carta 1 venceu" : "Carta 2 venceu", rDens);
    printf("PIB per Capita: %s (%d)\n",     rPibPc ? "Carta 1 venceu" : "Carta 2 venceu", rPibPc);
    printf("Super Poder: %s (%d)\n",        rSuper ? "Carta 1 venceu" : "Carta 2 venceu", rSuper);

    (void)super1; (void)super2;

    return 0;
}
