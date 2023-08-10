#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Node* current = head;
    while (current != NULL && current->data == 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("0\n");
        return;
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* addLists(Node* num1, Node* num2) {
    Node* result = NULL;
    Node* current = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;

        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        insertAtBeginning(&result, sum);
    }

    return result;
}

int main() {
    Node* num1 = NULL;
    Node* num2 = NULL;

    char ch;

    while (1) {
        ch = getchar();

        if (ch == '+' || ch == '=') {
            break;
        }

        if (ch >= '0' && ch <= '9') {
            int digit = ch - '0'; // Converter caractere numérico para inteiro
            insertAtBeginning(&num1, digit);
        }
    }

    while (1) {
        ch = getchar();

        if (ch == '=') {
            break;
        }

        if (ch >= '0' && ch <= '9') {
            int digit = ch - '0'; // Converter caractere numérico para inteiro
            insertAtBeginning(&num2, digit);
        }
    }

    Node* sum = addLists(num1, num2);

    printList(sum);

    return 0;
}
