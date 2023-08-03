#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Para usar a função toupper

#define TAMANHO_LINHA 100 // Tamanho inicial da linha

int main() {
    char *linha = (char *)malloc(TAMANHO_LINHA * sizeof(char));
    int tamanho_atual = TAMANHO_LINHA;
    int posicao = 0;
    char caractere;

    if (linha == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite o texto (Digite 'the end!' para encerrar):\n");

    while (1) {
        caractere = getchar();

        if (caractere == '\n' || caractere == EOF) {
            linha[posicao] = '\0'; // Adiciona o caractere de terminação da string

            if (strcmp(linha, "the end!") == 0) {
                break; // Encerra o loop quando encontra "the end!"
            }

            // Processar a linha atual (converter para maiúsculas e imprimir)
            for (int i = 0; linha[i] != '\0'; i++) {
                linha[i] = toupper(linha[i]);
            }

            printf("%s\n", linha);

            posicao = 0; // Reinicia a posição para a próxima linha
        } else {
            if (posicao >= tamanho_atual - 1) { // -1 para deixar espaço para o caractere '\0'
                tamanho_atual += TAMANHO_LINHA;
                char *linha_aux = (char *)realloc(linha, tamanho_atual * sizeof(char));
                if (linha_aux == NULL) {
                    printf("Erro ao realocar memória.\n");
                    free(linha);
                    return 1;
                }
                linha = linha_aux;
            }

            linha[posicao++] = caractere;
        }
    }

    free(linha);

    return 0;
}
