#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

void insertBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;

    do {
        if (curr->data == key) {
            if (curr == *head && curr->next == *head) {
                *head = NULL;
                free(curr);
                return;
            } else if (curr == *head) {
                prev = (*head)->prev;
                *head = (*head)->next;
                prev->next = *head;
                (*head)->prev = prev;
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            free(curr);
            return;
        }
        curr = curr->next;
    } while (curr != *head);

    printf("Node with key %d not found.\n", key);
}

void search(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Node with key %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Node with key %d not found.\n", key);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertBegin(&head, 5);

    display(head);

    search(head, 20);
    search(head, 50);

    printf("Deleting node with value 20...\n");
    deleteNode(&head, 20);

    display(head);

    return 0;
}