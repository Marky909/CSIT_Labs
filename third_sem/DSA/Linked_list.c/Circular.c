#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    }
    else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteFromEnd(struct Node** head)
{
    if (*head == NULL) {
        return;
    }
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
    else {
        struct Node* secondLast = *head;
        while (secondLast->next->next != *head) {
            secondLast = secondLast->next;
        }
        struct Node* last = secondLast->next;
        secondLast->next = *head;
        free(last);
    }
}

void traverse(struct Node* head)
{
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main()
{
    struct Node* head = NULL;

    // Insertion
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Traversal
    printf("Circular Linked List: ");
    traverse(head);

    // Deletion
    deleteFromEnd(&head);

    // Traversal after deletion
    printf("After deletion: ");
    traverse(head);

    return 0;
}