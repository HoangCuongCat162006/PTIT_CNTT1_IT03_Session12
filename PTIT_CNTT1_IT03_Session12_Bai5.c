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

struct Node* deleteByValue(struct Node* head, int value) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            struct Node* toDelete = current;

            if (toDelete->prev != NULL)
                toDelete->prev->next = toDelete->next;
            else
                head = toDelete->next;

            if (toDelete->next != NULL)
                toDelete->next->prev = toDelete->prev;

            current = toDelete->next;
            free(toDelete);
        } else {
            current = current->next;
        }
    }

    return head;
}

int main() {
    struct Node* node1 = createNode(5);
    struct Node* node2 = createNode(4);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(5);
    struct Node* node5 = createNode(2);
    struct Node* node6 = createNode(1);
    struct Node* node7 = createNode(5);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->prev = node5;
    node6->next = node7;
    node7->prev = node6;


    struct Node* head = node1;

    printList(head);

    int value;
    printf("Nhap so muon xoa : ");
    scanf("%d", &value);

    head = deleteByValue(head, value);

    printList(head);

    return 0;
}
