#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *curr = *head, *prev = NULL;

    if ((*head)->data == key && (*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    if ((*head)->data == key) {
        while (curr->next != *head) {
            curr = curr->next;
        }
        struct Node* temp = *head;
        curr->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
        return;
    }

    prev = *head;
    curr = (*head)->next;
    while (curr != *head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    } else {
        printf("Node with key %d not found.\n", key);
    }
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
    printf("Circular Singly Linked List: ");
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