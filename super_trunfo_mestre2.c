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
    unsigned long int pop, pop1;
    float area, area1;
    float pib, pib1;
    int pont_tur, pont_tur1;
    float densidade, densidade1;
    float pib_per_capita, pib_per_capita1;
    float poder, poder1;

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

            printf("\nCartas criadas com sucesso!\n");
            break;
    
        case 2:
            printf ("Comparar cartas:\n");

            //Menu para escolha dos atributos
            printf("\nEscolha o primeiro atributo para comparação: \n");
            printf("1 - População\n");
            printf("2 - Área\n");
            printf("3 - PIB\n");
            printf("4 - Densidade Demográfica\n");
            printf("5 - PIB per Capita\n");
            int atributo1;
            scanf("%d", &atributo1);

            printf("\nEscolha o segundo atributo para comparação: \n");
            for (int i = 1; i <= 5; i++) {
                if (i == atributo1) continue;
                switch (i){
                    case 1: printf("1 - População\n"); break;
                    case 2: printf("2 - Área\n"); break;
                    case 3: printf("3 - PIB\n"); break;
                    case 4: printf("4 - Densidade Demográfica\n"); break;
                    case 5: printf("5 - PIB per Capita\n"); break;
                }
            }
            int atributo2;
            scanf("%d", &atributo2);

            //Função auxiliar para pegar valores
            float valor1_attr1, valor2_attr1, valor1_attr2, valor2_attr2;

            switch (atributo1) {
                case 1: valor1_attr1 = pop; valor2_attr1 = pop1; break;
                case 2: valor1_attr1 = area; valor2_attr1 = area1; break;
                case 3: valor1_attr1 = pib; valor2_attr1 = pib1; break;
                case 4: valor1_attr1 = densidade; valor2_attr1 = densidade1; break;
                case 5: valor1_attr1 = pib_per_capita; valor2_attr1 = pib_per_capita1; break;
                default: printf("Atributo inválido!\n"); return 0;
            }

            switch (atributo2) {
                case 1: valor1_attr2 = pop; valor2_attr2 = pop1; break;
                case 2: valor1_attr2 = area; valor2_attr2 = area1; break;
                case 3: valor1_attr2 = pib; valor2_attr2 = pib1; break;
                case 4: valor1_attr2 = densidade; valor2_attr2 = densidade1; break;
                case 5: valor1_attr2 = pib_per_capita; valor2_attr2 = pib_per_capita1; break;
                default: printf("Atributo inválido!\n"); return 0;
            }

            //Comparação dos atributos
            int vencedor_attr1 = (atributo1 == 4) ? (valor1_attr1 > valor2_attr1 ? 1 : 2) : (valor1_attr1 > valor2_attr1 ? 1 : 2);
            int vencedor_attr2 = (atributo2 == 4) ? (valor1_attr2 > valor2_attr2 ? 1 : 2) : (valor1_attr2 > valor2_attr2 ? 1 : 2);

            //Soma dos atributos
            float soma1 = valor1_attr1 + valor1_attr2;
            float soma2 = valor2_attr1 + valor2_attr2;
            int vencedor_final = (soma1 > soma2) ? 1 : (soma1 < soma2 ? 2 : 0);
            
            //Exibição dos resultados
            printf("\n--- Carta 1 ---\nEstado: %s\nNome da Cidade: %s\n", estado, nome);
            printf("\n--- Carta 2 ---\nEstado: %s\nNome da Cidade: %s\n", estado1, nome1);

            printf("Atributo 1 escolhido: Carta %d venceu\n", vencedor_attr1);
            printf("Valores: %s = %.2f | %s = %.2f\n\n", estado, valor1_attr1, estado1, valor2_attr1);

            printf("Atributo 2 escolhido: Carta %d venceu\n", vencedor_attr2);
            printf("Valores: %s = %.2f | %s = %.2f\n\n", estado, valor1_attr2, estado1, valor2_attr2);

            printf("Soma dos atributos:\n%s = %.2f | %s = %.2f\n", estado, soma1, estado1, soma2);

            if (vencedor_final == 0) {
                printf ("\nResultado Final: Empate!\n");
            } else {
                printf ("\nResultado Final: Carta %d venceu!\n", vencedor_final);
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}