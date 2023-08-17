#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mynode
{
    struct mynode *next;
    char letter; //cada posicao da estrutura contem um caracter dentro dos 256 possiveis da tabela ASCII
    int frequency;
}node;
node* create_linked_list()
{
    return NULL;
}
node* add(char c, int freq)
{
    node *new_node = (node*) malloc(sizeof(node));
    if(new_node == NULL)
    {
        exit(1);
    }
    new_node->letter = c;
    new_node->frequency = freq;
    new_node->next = NULL;
    
    return new_node;
}
node* analyze(char* phrase, int size)
{
    node* head = create_linked_list();
    node* tail = create_linked_list();
    int letter_freq[256] = {0};
    int i;

    for(i = 0; i < size; i++) //percorrer o array de caracteres phrase
    {
        letter_freq[(int) phrase[i]]++; //cada letra ser� o indice em ASCII de cada posicao do array de caracter
    }

    for(i = 0; i < 256; i++)
    {
        if(letter_freq[i] > 0)
        {
            if( head == NULL)
            {
                head = add((char) i, letter_freq[i]);
                tail = head;
            }
            else{
                tail->next = add((char) i, letter_freq[i]);
                tail = tail->next;

            }
        }
    }
    return head;
}
void print_linked_list_reverse(node* head)
{
    if(head == NULL) //caso base: se a lista est� vazia ou chegou ao final, retorna
    {
        return;
    }
    else //chamada recursiva para percorrer a lista do fim para o come�o
    {
        print_linked_list_reverse(head->next);
        printf("%c %d\n", head->letter, head->frequency);
        head = head->next; //imprime o caractere e sua frequ�ncia
    }
}
int main()
{
    char phrase[256];
    fgets(phrase, 256, stdin); 
    int n = strlen(phrase);
    node* list = create_linked_list();
    list = analyze(&phrase, n);
    node* pointer = list;
    print_linked_list_reverse(pointer);
    free(list);

}