#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
}node;


node *create_linked_list()
{
    return NULL;
}

// Função para adicionar um novo nó no início da lista
node *insert_at_beginning(node *head, int item)
{
    node *new_node = malloc(sizeof(node));
    new_node->item = item;
    new_node->next = head;
    return new_node;
}

node *insert_at_end(node *head, int item){
    node *new_node = malloc(sizeof(node));
    new_node ->item = item;
    new_node ->next = NULL;

    if (head==NULL)
    {
        return new_node;
    }

    else
    {
        node *current = head;
        while (current->next != NULL)
        {
            current = current-> next;
        }
        
        current->next = new_node;
        return head;
    }
    
    
    
}

void print_linked_list(node *head)
{
    if (!is_empty(head))
    {
        printf("%d\n", head->item);
        print_linked_list(head->next);
    }
}

int is_empty(node *head){
    return (head == NULL);
}


void encontrarMaiorSequenciaZeros(const char *entrada) {
    int tamanho = strlen(entrada);
    int inicioMaior = -1, fimMaior = -1;
    int inicioAtual = -1, fimAtual = -1;
    int contador = 0;

    for (int i = 0; i < tamanho; i++) {
        if (entrada[i] == '0') {
            if (inicioAtual == -1) {
                inicioAtual = i;
            }
            contador++;
            fimAtual = i;
        } else {
            if (contador > (fimMaior - inicioMaior + 1)) {
                inicioMaior = inicioAtual;
                fimMaior = fimAtual;
            }
            inicioAtual = -1;
            contador = 0;
        }
    }

    if (contador > (fimMaior - inicioMaior + 1)) {
        inicioMaior = inicioAtual;
        fimMaior = fimAtual;
    }

    if (inicioMaior != -1) {
        printf("%d %d\n", inicioMaior, fimMaior);
    } else {
        int posicaoUnicoZero = -1;
        for (int i = 0; i < tamanho; i++) {
            if (entrada[i] == '0') {
                if (posicaoUnicoZero == -1) {
                    posicaoUnicoZero = i;
                } else {
                    posicaoUnicoZero = -1;
                    break;
                }
            }
        }

        if (posicaoUnicoZero != -1) {
            printf("%d %d", posicaoUnicoZero,posicaoUnicoZero);
        } else {
            printf("Não foi encontrada nenhuma sequência de zeros.\n");
        }
    }
}





int main()
{

    char entrada [50000];

    for (int i = 0; i < 50000; i++)
    {
        scanf("%s",entrada);    
        if (strcmp(entrada,"0")==0)
        {
            break;
        }

        encontrarMaiorSequenciaZeros(entrada);
        
    }
    

    return 0;
}