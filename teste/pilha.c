#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *anterior;
} node;

node *topo;

node *create_stack()
{
    return NULL;
}

node *push(node *stack, int item)
{
    node *new_node = malloc(sizeof(node));
    new_node->item = item;
    new_node->anterior = stack;
    topo = new_node;

    return new_node;
}

node *pop(node *stack)
{
    if (stack == NULL)
    {
        printf("Pilha vazia. Não é possível realizar pop.\n");
        return NULL;
    }
    node *aux = topo;
    topo = stack->anterior;
    free(aux);

    return topo;
}

void print_stack(node *topo)
{
    node *current = topo;

    while (current != NULL)
    {
        printf("%d ", current->item);
        current = current->anterior;
    }
}

int main()
{

    node *pilha = create_stack();

    pilha = push(pilha, 3);
    pilha = push(pilha, 4);
    pilha = push(pilha, 5);
    pilha = push(pilha, 6);
    pilha = pop(pilha);
    pilha = pop(pilha);
    print_stack(pilha);

    return 0;
}