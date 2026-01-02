#include <stdio.h>

int main() {
    char estado[50];
    char estado1[50];
    char codigo[10];
    char codigo1[10];
    char nome[50];
    char nome1[50];
    int pop;
    int pop1;
    float area;
    float area1;
    float pib;
    float pib1;
    int pont_tur;
    int pont_tur1;
    
    printf ("--- Super Trunfo ---\n");
    printf ("Dê espaço para adicionar nova carta em cada pergunta, assim que finalizar, aperte enter\n");

    printf ("Qual o nome dos estados: \n");
    scanf ("%49s %49s", estado, estado1);

    printf ("Qual os códigos das cartas: \n");
    scanf ("%9s %9s", codigo, codigo1);

    printf ("Qual os nomes das cidades: \n");
    scanf ("%49s %49s", nome, nome1);

    printf ("Qual os tamanhos das populações: \n");
    scanf ("%d %d", &pop, &pop1);

    printf ("Qual o tamanho da Área em Km²: \n");
    scanf ("%f %f", &area, &area1);

    printf ("Qual o PIB dessa cidade: \n");
    scanf ("%f %f", &pib, &pib1);

    printf ("Quantos são os pontos turísticos: \n");
    scanf ("%d %d", &pont_tur, &pont_tur1);

    printf ("\n--- Carta 1 ---\n");
    printf ("Estado: %s\nCódigo: %s\nNome da Cidade: %s\nPopulação: %d\nÁrea: %.2f Km²\nPIB: %.2f bilhões de reais\nNúmero de Pontos Turísticos: %d\n",
            estado, codigo, nome, pop, area, pib, pont_tur);

    printf ("\n--- Carta 2 ---\n");
    printf ("Estado: %s\nCódigo: %s\nNome da Cidade: %s\nPopulação: %d\nÁrea: %.2f Km²\nPIB: %.2f bilhões de reais\nNúmero de Pontos Turísticos: %d\n",
            estado1, codigo1, nome1, pop1, area1, pib1, pont_tur1);

    return 0;
}