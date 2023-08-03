#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Para usar a função toupper

#define TAMANHO_LINHA 100 // Tamanho inicial da linha

int main()
{
    char *linha = malloc(TAMANHO_LINHA * sizeof(char));
    int posicao = 0;
    char caractere;

    if (linha == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    while (1)
    {
        caractere = getchar();

        if (caractere == '\n' || caractere == EOF)
        {
            linha[posicao] = '\0'; // Adiciona o caractere de terminação da string

            if (strcmp(linha, "the end!") == 0)
            {
                break; // Encerra o loop quando encontra "the end!"
            }

            // Processar a linha atual (converter para maiúsculas e imprimir)
            for (int i = 0; linha[i] != '\0'; i++)
            {
                linha[i] = toupper(linha[i]);
            }

            printf("%s\n", linha);

            posicao = 0; // Reinicia a posição para a próxima linha
        }
        else
        {
            linha[posicao] = caractere;
            posicao++;
        }
    }

    free(linha);

    return 0;
}
