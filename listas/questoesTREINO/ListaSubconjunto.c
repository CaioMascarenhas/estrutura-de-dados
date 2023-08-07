#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
} node;

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

node *insert_at_end(node *head, int item)
{
    node *new_node = malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;

    if (head == NULL)
    {
        return new_node;
    }

    else
    {
        node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
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

int is_empty(node *head)
{
    return (head == NULL);
}

void VerificaSubconjunto(node *head1, node *head2, int tamanho_lista_1, int tamanho_lista_2)
{
    int aux = 0;
    node *current1 = head1;
    node *current2 = head2;

    while (current2 != NULL)
    {

        if (current1 == NULL)
        {
            printf("0");
            return;
        }

        if (current2->item == current1->item)
        {
            aux++;
            current2 = current2->next;
            current1 = head1;
        }
        else
        {
            if (current1->next == NULL)
            {
                current2 = current2->next;
            }
            current1 = current1->next;
        }
        
    }
    if (aux==tamanho_lista_2)
    {   
        
        printf("1");
    }
    else
        printf("0");
    
}

int main()
{

    node *list1 = create_linked_list();
    node *list2 = create_linked_list();

    int tamanho_lista_1;
    int tamanho_lista_2;
    int aux;

    scanf("%d", &tamanho_lista_1);

    for (int i = 0; i < tamanho_lista_1; i++)
    {
        scanf("%d", &aux);
        list1 = insert_at_end(list1, aux);
    }

    scanf("%d", &tamanho_lista_2);

    for (int i = 0; i < tamanho_lista_2; i++)
    {
        scanf("%d", &aux);
        list2 = insert_at_end(list2, aux);
    }

    VerificaSubconjunto(list1,list2,tamanho_lista_1,tamanho_lista_2);
    free(list1);
    free(list2);

    return 0;
}