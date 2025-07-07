#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL)
            printf("<->");
        current = current->next;
    }
    printf("->NULL\n");
}

struct Node* deleteTail(struct Node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);

    return head;
}

int main() {
    struct Node* node1 = createNode(5);
    struct Node* node2 = createNode(4);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(2);
    struct Node* node5 = createNode(1);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    struct Node* head = node1;
    printList(head);

    head = deleteTail(head);

    printList(head);

    return 0;
}
