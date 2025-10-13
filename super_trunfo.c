#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#ifdef _WIN32
  #include <fcntl.h>
  #include <io.h>
#endif

typedef struct {
    wchar_t estado;
    wchar_t codigo[5];
    wchar_t cidade[50];
    int     populacao;
    float   area_km2;
    float   pib_bilhoes;
    int     pontos_turisticos;
} Carta;

int main(void) {
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");

    #ifdef _WIN32
      _setmode(_fileno(stdout), _O_U16TEXT);
      _setmode(_fileno(stdin),  _O_U16TEXT);
      _setmode(_fileno(stderr), _O_U16TEXT);
    #endif

    Carta c1;

    wprintf(L"=== Cadastro da Carta 1 ===\n");

    wprintf(L"Estado (A-H): ");
    wscanf(L" %lc", &c1.estado);

    wprintf(L"Código (ex: A01): ");
    wscanf(L" %4ls", c1.codigo);

    wprintf(L"Nome da Cidade: ");
    wscanf(L" %49[^\n]ls", c1.cidade);

    wprintf(L"População (número inteiro): ");
    wscanf(L" %d", &c1.populacao);

    wprintf(L"Área em km² (use ponto, ex: 1521.11): ");
    wscanf(L" %f", &c1.area_km2);

    wprintf(L"PIB em bilhões (use ponto, ex: 699.28): ");
    wscanf(L" %f", &c1.pib_bilhoes);

    wprintf(L"Número de Pontos Turísticos: ");
    wscanf(L" %d", &c1.pontos_turisticos);

    Carta c2;

    wprintf(L"\n=== Cadastro da Carta 2 ===\n");

    wprintf(L"Estado (A-H): ");
    wscanf(L" %lc", &c2.estado);

    wprintf(L"Código (ex: A01): ");
    wscanf(L" %4ls", c2.codigo);

    wprintf(L"Nome da Cidade: ");
    wscanf(L" %49[^\n]ls", c2.cidade);

    wprintf(L"População (número inteiro): ");
    wscanf(L" %d", &c2.populacao);

    wprintf(L"Área em km² (use ponto, ex: 1200.25): ");
    wscanf(L" %f", &c2.area_km2);

    wprintf(L"PIB em bilhões (use ponto, ex: 300.50): ");
    wscanf(L" %f", &c2.pib_bilhoes);

    wprintf(L"Número de Pontos Turísticos: ");
    wscanf(L" %d", &c2.pontos_turisticos);

    wprintf(L"\nCarta 1:\n");
    wprintf(L"Estado: %lc\n", c1.estado);
    wprintf(L"Código: %ls\n", c1.codigo);
    wprintf(L"Nome da Cidade: %ls\n", c1.cidade);
    wprintf(L"População: %d\n", c1.populacao);
    wprintf(L"Área: %.2f km\u00B2\n", c1.area_km2);
    wprintf(L"PIB: %.2f bilhões de reais\n", c1.pib_bilhoes);
    wprintf(L"Número de Pontos Turísticos: %d\n", c1.pontos_turisticos);

    wprintf(L"\nCarta 2:\n");
    wprintf(L"Estado: %lc\n", c2.estado);
    wprintf(L"Código: %ls\n", c2.codigo);
    wprintf(L"Nome da Cidade: %ls\n", c2.cidade);
    wprintf(L"População: %d\n", c2.populacao);
    wprintf(L"Área: %.2f km\u00B2\n", c2.area_km2);
    wprintf(L"PIB: %.2f bilhões de reais\n", c2.pib_bilhoes);
    wprintf(L"Número de Pontos Turísticos: %d\n", c2.pontos_turisticos);

    return 0;
}
