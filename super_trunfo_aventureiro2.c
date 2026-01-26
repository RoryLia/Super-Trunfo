#include <stdio.h>

//Arrumar o erro do trabalho anterior onde usei scanf para ler strings, alémde adaptar para a estrutura de comparação de cartas.

void limpa_enter(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0'; // substitui o \n por fim de string
            break;
        }
        i++;
    }
}

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

    printf ("MENU DE OPÇÕES:\n");
    printf ("1 - Criar cartas\n");
    printf ("2 - Comparar cartas\n");
    printf ("Escolha uma opção: \n");
    int opcao;
    scanf ("%d", &opcao);
    getchar();

    switch (opcao)
    {
        case 1:
            printf ("Criar cartas:\n");

            printf ("Qual o nome do primeiro estado: \n");
            fgets(estado, sizeof(estado), stdin);
            limpa_enter(estado);

            printf ("Qual o nome do segundo estado: \n");
            fgets(estado1, sizeof(estado1), stdin);
            limpa_enter(estado1);

            printf ("Qual o código da primeira carta: \n");
            fgets(codigo, sizeof(codigo), stdin);
            limpa_enter(codigo);

            printf ("Qual o código da segunda carta: \n");
            fgets(codigo1, sizeof(codigo1), stdin);
            limpa_enter(codigo1);

            printf ("Qual o nome da primeira cidade: \n");
            fgets(nome, sizeof(nome), stdin);
            limpa_enter(nome);

            printf ("Qual o nome da segunda cidade: \n");
            fgets(nome1, sizeof(nome1), stdin);
            limpa_enter(nome1);

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
            break;
    
        case 2:
            printf ("Comparar cartas:\n");
            printf("\n--- Carta 1 ---\n");
            printf ("Estado: %s\nCódigo: %s\nNome da Cidade: %s\nPopulação: %lu\nÁrea: %.2f Km²\nPIB: %.2f bilhões de reais\nNúmero de Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/Km²\nPIB per Capita: %.2f reais\nSuper Poder: %.2f\n",
            estado, codigo, nome, pop, area, pib, pont_tur, densidade, pib_per_capita, poder);

            printf ("\n--- Carta 2 ---\n");
            printf ("Estado: %s\nCódigo: %s\nNome da Cidade: %s\nPopulação: %lu\nÁrea: %.2f Km²\nPIB: %.2f bilhões de reais\nNúmero de Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/Km²\nPIB per Capita: %.2f reais\nSuper Poder: %.2f\n",
            estado1, codigo1, nome1, pop1, area1, pib1, pont_tur1, densidade1, pib_per_capita1, poder1);

            printf ("\nComparação das Cartas:\n");

            //Comparação fixa: PIB per Capita
            if (pib_per_capita > pib_per_capita1) {
                printf ("A carta 1 venceu!");
            } else if (pib_per_capita < pib_per_capita1) {
                printf ("A carta 2 venceu!");
            } else {
                printf ("Empate na categoria PIB per Capita!");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}