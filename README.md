# 🃏 Super Trunfo

O programa foi desenvolvido em **C**, utilizando o **MinGW** para compilação e testes no ambiente **Windows**.  
Os dados são lidos diretamente do usuário e exibidos de forma organizada e legível.


---
## 🧠 1- NIVEL NOVATO
---


Neste desafio inicial do Super Trunfo de Países, o objetivo é criar um programa em C que permita o cadastro e exibição de duas cartas representando cidades. Cada carta deve conter informações como estado, código, nome da cidade, população, área, PIB e número de pontos turísticos.
O programa deve ler os dados digitados pelo usuário, armazená-los em variáveis apropriadas e depois exibi-los formatados na tela, sem utilizar estruturas de repetição ou decisão.
O foco deste nível é praticar entrada e saída de dados, organização do código e clareza na exibição das informações.


## 🧩 Como compilar e executar

No terminal (CMD ou PowerShell), dentro da pasta do projeto:

```bash
gcc super_trunfo_novato.c -o super_trunfo_novato -Wall -Wextra -std=c11
super_trunfo_novato
```

---
## 🧠 2- NIVEL AVENTUREIRO

Neste nível Aventureiro do projeto Super Trunfo de Países, o objetivo é aprimorar o programa em C criado anteriormente, adicionando cálculos automáticos para Densidade Populacional e PIB per Capita de duas cidades.
O programa deve continuar lendo os mesmos dados (estado, código, nome da cidade, população, área, PIB e pontos turísticos), mas agora também deve:

Calcular a densidade populacional (população ÷ área).

Calcular o PIB per capita (PIB ÷ população).

Exibir os resultados formatados com duas casas decimais, junto às demais informações da carta.

O projeto mantém as boas práticas do nível básico — legibilidade, clareza e corretude — e deve continuar sem utilizar estruturas de repetição ou decisão.
O foco deste nível é aplicar operações matemáticas em C e aprimorar a organização e exibição dos dados do jogo.


## 🧩 Como compilar e executar

No terminal (CMD ou PowerShell), dentro da pasta do projeto:

```bash
gcc super_trunfo_aventureiro.c -o super_trunfo_aventureiro -Wall -Wextra -std=c11
super_trunfo_aventureiro
```

---

## 🧠 3- NIVEL MESTRE

Neste nível avançado do Super Trunfo de Países, você evolui o programa em C para comparar duas cartas e determinar vencedores por atributo, incluindo um novo indicador: Super Poder. A população passa a ser unsigned long int; demais tipos permanecem.

O que o programa faz:

Lê os dados de duas cartas (estado, código, cidade, população unsigned long int, área, PIB, pontos turísticos).

Calcula:

Densidade populacional = população ÷ área (quanto menor, melhor).

PIB per capita = PIB ÷ população.

Super Poder (float) = população + área + PIB + pontos turísticos + PIB per capita + (1 ÷ densidade) — atenção às conversões de tipo.

Compara atributo a atributo (população, área, PIB, pontos turísticos, densidade, PIB per capita e Super Poder):

Menor densidade vence; nos demais, maior valor vence.

Exibe o resultado de cada comparação indicando a carta vencedora e o valor 1 (Carta 1 venceu) ou 0 (Carta 2 venceu).

Foco: operadores relacionais, conversões/“casting” e organização clara da saída. Resultado: um sistema de batalha de cartas robusto, eficiente e pronto para demonstrar sua maestria em C.


## 🧩 Como compilar e executar

No terminal (CMD ou PowerShell), dentro da pasta do projeto:

```bash
gcc super_trunfo_mestre.c -o super_trunfo_mestre -Wall -Wextra -std=c11
super_trunfo_mestre
```

---


projeto desenvolvido pelo aluno: Alan Oliveira
---
