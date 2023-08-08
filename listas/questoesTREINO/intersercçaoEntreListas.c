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

void bubble_sort(node *head)
{
    if (is_empty(head) || is_empty(head->next))
        return;

    int swapped;
    node *ptr1;
    node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->item > ptr1->next->item)
            {
                int temp = ptr1->item;
                ptr1->item = ptr1->next->item;
                ptr1->next->item = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


/*void procedimento(node *lista, node *lista2)
{
    node *listaux = create_linked_list();
    node *current1 = lista;
    node *current2 = lista2;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (current2->item == current1->item)
            {
                listaux = insert_at_end(listaux, current1->item);
                current1 = current1->next;
            }
            else
            {
                current1 = current1->next;
            }
        }
        current1 = lista;
        current2 = current2->next;
    }
    if (is_empty(listaux)==1)
    {
        printf("VAZIO");
    }
    else{
        bubble_sort(listaux);
    print_linked_list(listaux);
    }
}*/

void procedimento(node *lista, node *lista2)
{
    node *listaux = create_linked_list();
    node *current1 = lista;
    node *current2 = lista2;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (current2->item == current1->item)
            {
                // Verifica se o item já não está na listaux antes de inserir
                int found = 0;
                node *auxNode = listaux;
                while (auxNode != NULL)
                {
                    if (auxNode->item == current1->item)
                    {
                        found = 1;
                        break;
                    }
                    auxNode = auxNode->next;
                }

                if (!found)
                {
                    listaux = insert_at_end(listaux, current1->item);
                }

                current1 = current1->next;
            }
            else
            {
                current1 = current1->next;
            }
        }
        current1 = lista;
        current2 = current2->next;
    }

    if (is_empty(listaux) == 1)
    {
        printf("VAZIO");
    }
    else
    {   
        bubble_sort(listaux);
        print_linked_list(listaux);
    }
}


int main()
{

    node *list = create_linked_list();
    node *list2 = create_linked_list();

    for (int i = 0; i < 20; i++)
    {
        int aux;
        scanf("%d", &aux);
        list = insert_at_end(list, aux);
    }

    for (int i = 0; i < 20; i++)
    {
        int aux;
        scanf("%d", &aux);
        list2 = insert_at_end(list2, aux);
    }

    procedimento(list, list2);

    return 0;
}
