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
        printf("(%d)", head->item);
        print_linked_list(head->next);
    }
}

int is_empty(node *head){
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

node *Copy_List(node *list, node *list2) {
    
    while (list !=NULL)
    {
        list2 = insert_at_beginning(list2, list->item);
        list = list->next;
    }
    return list2;
    
}


int main()
{

    node *list = create_linked_list();
    node *list2 = create_linked_list();
    
    int tamanho;
    scanf("%d",&tamanho);
    
    for (int i = 0; i < tamanho; i++)
    {   
        int aux;
        scanf("%d",&aux);
        list = insert_at_end(list,aux);
    }

    bubble_sort(list);
    list2 = Copy_List(list,list2);

    printf("Tamanho = %d\n",tamanho);
    print_linked_list(list);
    printf("\n");
    printf("Tamanho = %d\n",tamanho);
    print_linked_list(list2);
    printf("\n");
    printf("Tamanho = %d\n",tamanho);
    print_linked_list(list);

    

    return 0;
}