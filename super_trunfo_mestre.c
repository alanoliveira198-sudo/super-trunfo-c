#include <stdio.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>  // SetConsoleOutputCP / SetConsoleCP
#endif

typedef struct {
    char estado;
    char codigo[5];              // ex: A01
    char cidade[50];             // com espaços
    unsigned long int populacao; // agora ULI
    float area_km2;              // km²
    float pib_bilhoes;           // bilhões de reais (entrada)
    int pontos_turisticos;       // quantidade
} Carta;

int main(void) {
    // UTF-8 no console do Windows (dispensa chcp 65001)
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
    #endif

    // Acentos e separador decimal com ponto
    setlocale(LC_ALL, "pt_BR.UTF-8");
    setlocale(LC_NUMERIC, "C");

    Carta c1, c2;

    // -------- Entrada Carta 1 --------
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c%*[^\n]", &c1.estado);

    printf("Código (ex: A01): ");
    scanf(" %4s%*[^\n]", c1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c1.cidade);

    printf("População (número inteiro): ");
    scanf(" %lu%*[^\n]", &c1.populacao);

    printf("Área em km² (use ponto, ex: 1521.11): ");
    scanf(" %f%*[^\n]", &c1.area_km2);

    printf("PIB em bilhões (use ponto, ex: 699.28): ");
    scanf(" %f%*[^\n]", &c1.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf(" %d%*[^\n]", &c1.pontos_turisticos);

    // -------- Entrada Carta 2 --------
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c%*[^\n]", &c2.estado);

    printf("Código (ex: A01): ");
    scanf(" %4s%*[^\n]", c2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c2.cidade);

    printf("População (número inteiro): ");
    scanf(" %lu%*[^\n]", &c2.populacao);

    printf("Área em km² (use ponto, ex: 1200.25): ");
    scanf(" %f%*[^\n]", &c2.area_km2);

    printf("PIB em bilhões (use ponto, ex: 300.50): ");
    scanf(" %f%*[^\n]", &c2.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf(" %d%*[^\n]", &c2.pontos_turisticos);

    // -------- Cálculos em double --------
    // Densidade
    double dens1_d = (double)c1.populacao / (double)c1.area_km2;
    double dens2_d = (double)c2.populacao / (double)c2.area_km2;
    float dens1 = (float)dens1_d;
    float dens2 = (float)dens2_d;

    // PIB per capita
    const double BILHAO = 1000000000.0;
    double pib1_reais = (double)c1.pib_bilhoes * BILHAO;
    double pib2_reais = (double)c2.pib_bilhoes * BILHAO;
    double pibpc1_d = pib1_reais / (double)c1.populacao;
    double pibpc2_d = pib2_reais / (double)c2.populacao;
    float pibpc1 = (float)pibpc1_d;
    float pibpc2 = (float)pibpc2_d;

    // Inverso da densidade
    double invdens1_d = 1.0 / dens1_d;
    double invdens2_d = 1.0 / dens2_d;

    // Super Poder: somatório em double; armazenar também em float (requisito)
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

    float super1 = (float)super1_D; // armazenamento em float (como pedido)
    float super2 = (float)super2_D;

    // -------- Saída das cartas --------
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
    printf("Super Poder: %.2f\n", super1_D); // imprime o double (preciso)

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
    printf("Super Poder: %.2f\n", super2_D); // imprime o double (preciso)

    // -------- Comparações (1 = Carta 1 vence; 0 = Carta 2 vence) --------
    int rPop      = (c1.populacao        > c2.populacao);
    int rArea     = (c1.area_km2         > c2.area_km2);
    int rPIB      = (c1.pib_bilhoes      > c2.pib_bilhoes);
    int rPontos   = (c1.pontos_turisticos> c2.pontos_turisticos);
    int rDens     = (dens1               < dens2);   // menor densidade vence
    int rPibPc    = (pibpc1              > pibpc2);
    int rSuper    = (super1_D            > super2_D); // compara em double

    printf("\nComparação de Cartas:\n");
    printf("População: %s (%d)\n",         rPop   ? "Carta 1 venceu" : "Carta 2 venceu", rPop);
    printf("Área: %s (%d)\n",               rArea  ? "Carta 1 venceu" : "Carta 2 venceu", rArea);
    printf("PIB: %s (%d)\n",                rPIB   ? "Carta 1 venceu" : "Carta 2 venceu", rPIB);
    printf("Pontos Turísticos: %s (%d)\n",  rPontos? "Carta 1 venceu" : "Carta 2 venceu", rPontos);
    printf("Densidade Populacional: %s (%d)\n", rDens ? "Carta 1 venceu" : "Carta 2 venceu", rDens);
    printf("PIB per Capita: %s (%d)\n",     rPibPc ? "Carta 1 venceu" : "Carta 2 venceu", rPibPc);
    printf("Super Poder: %s (%d)\n",        rSuper ? "Carta 1 venceu" : "Carta 2 venceu", rSuper);

    // evita warnings por variáveis não usadas (super1/super2 armazenados em float por requisito)
    (void)super1; (void)super2;

    return 0;
}
