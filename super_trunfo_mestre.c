#include <stdio.h>

int main() {
    char estado[50];
    char estado1[50];
    char codigo[10];
    char codigo1[10];
    char nome[50];
    char nome1[50];
    unsigned long int pop;
    unsigned long int pop1;
    float area;
    float area1;
    float pib;
    float pib1;
    int pont_tur;
    int pont_tur1;
    float densidade;
    float densidade1;
    float pib_per_capita;
    float pib_per_capita1;
    float poder;
    float poder1;

    printf ("--- Super Trunfo ---\n");
    printf ("Dê espaço para adicionar nova carta em cada pergunta, assim que finalizar, aperte enter\n");

    printf ("Qual o nome dos estados: \n");
    scanf ("%49s %49s", estado, estado1);

    printf ("Qual os códigos das cartas: \n");
    scanf ("%9s %9s", codigo, codigo1);

    printf ("Qual os nomes das cidades: \n");
    scanf ("%49s %49s", nome, nome1);

    printf ("Qual os tamanhos das populações: \n");
    scanf ("%lu %lu", &pop, &pop1);

    printf ("Qual o tamanho da Área em Km²: \n");
    scanf ("%f %f", &area, &area1);

    printf ("Qual o PIB dessa cidade: \n");
    scanf ("%f %f", &pib, &pib1);

    printf ("Quantos são os pontos turísticos: \n");
    scanf ("%d %d", &pont_tur, &pont_tur1);

    // Calcular atributos
    densidade = (float) pop / area;
    densidade1 = (float) pop1 / area1;
    pib_per_capita = (float) pib / pop;
    pib_per_capita1 = (float) pib1 / pop1;
    poder = (float)pop + area + pib + (float)pont_tur + pib_per_capita + (1.0f / densidade);
    poder1 = (float)pop1 + area1 + pib1 + (float)pont_tur1 + pib_per_capita1 + (1.0f / densidade1);

    printf("\nCalculando atributos das cartas...\n");

    printf ("\n--- Carta 1 ---\n");
    printf ("Estado: %s\nCódigo: %s\nNome da Cidade: %s\nPopulação: %lu\nÁrea: %.2f Km²\nPIB: %.2f bilhões de reais\nNúmero de Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/Km²\nPIB per Capita: %.2f reais\nSuper Poder: %.2f\n",
            estado, codigo, nome, pop, area, pib, pont_tur, densidade, pib_per_capita, poder);

    printf ("\n--- Carta 2 ---\n");
    printf ("Estado: %s\nCódigo: %s\nNome da Cidade: %s\nPopulação: %lu\nÁrea: %.2f Km²\nPIB: %.2f bilhões de reais\nNúmero de Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/Km²\nPIB per Capita: %.2f reais\nSuper Poder: %.2f\n",
            estado1, codigo1, nome1, pop1, area1, pib1, pont_tur1, densidade1, pib_per_capita1, poder1);

    printf("\nComparação de Cartas:\n");

    // Comparações
    int vence_pop = (pop > pop1) ? 1 : 0;
    int vence_area = (area > area1) ? 1 : 0;
    int vence_pib = (pib > pib1) ? 1 : 0;
    int vence_pont_tur = (pont_tur > pont_tur1) ? 1 : 0;
    int vence_densidade = (densidade < densidade1) ? 1 : 0;
    int vence_pib_per_capita = (pib_per_capita > pib_per_capita1) ? 1 : 0;
    int vence_poder = (poder > poder1) ? 1 : 0;

    printf("População: Carta %d venceu (%d)\n", vence_pop ? 1 : 2, vence_pop);
    printf("Área: Carta %d venceu (%d)\n", vence_area ? 1 : 2, vence_area);
    printf("PIB: Carta %d venceu (%d)\n", vence_pib ? 1 : 2, vence_pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", vence_pont_tur ? 1 : 2, vence_pont_tur);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", vence_densidade ? 1 : 2, vence_densidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", vence_pib_per_capita ? 1 : 2, vence_pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", vence_poder ? 1 : 2, vence_poder);

    return 0;
}