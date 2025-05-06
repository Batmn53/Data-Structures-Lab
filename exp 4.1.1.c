//
// Created by Mohammed on 5/5/2025.
//
/*Write a menu-driven program that implements a singly linked list for the following operations:

Insert
Delete
Reverse
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct LinkedList* initializeList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (list == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void insert(struct LinkedList* list, int data, int position) {
    struct Node* node = list->head;
    if(position==0) {
        struct Node* n = createNode(data);
        list->head = n;
    }
    for(int i = 0; i < position-1; i++) {
        if(node->next==NULL) {
            printf("Invalid position\n");
            return;
        }
        node = node->next;
    }
    struct Node* n = createNode(data);
    n->next=node->next;
    node->next=n;
    printf("Element %d inserted at position %d\n",data,position);
}
void deleteNode(struct LinkedList* list, int position) {
    struct Node* n = list->head;
    if((position==0&&list->head==NULL)||(position==1&&list->head->next==NULL)) {
        printf("Invalid position\n");
        return;
    }
    if(position==0) {
        struct Node* temp = n;
        list->head=temp->next;
        free(temp);
    }
    for(int i = 0; i < position-1; i++) {
        if(n->next==NULL) {
            printf("Invalid position\n");
            return;
        }
        n = n->next;
    }
    printf("Element at position %d deleted\n", position);
    struct Node* temp = n->next;
    n->next = n->next->next;
    free(temp);
}
void reverse(struct LinkedList* list) {
    struct Node* n = list->head;
    if(n->next==NULL) return;
    struct Node *a = n->next, *prev = n, *temp=n->next->next;
    if(n->next->next==NULL) {
        struct Node* temp = n->next;
        temp->next = n;
        n->next = NULL;
    } else {
        n->next=NULL;
        while(temp!=NULL) {
            a->next=prev;
            prev=a;
            a=temp;
            temp=temp->next;
        }
        a->next=prev;
    }
    list->head=a;
}
void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayReversed(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int num_elements;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &num_elements);
    struct LinkedList* list = initializeList();
    int data;
    printf("Enter the elements:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &data);
        insert(list, data, i);
    }
    int choice, position;
    while (1) {
        printf("Linked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Reverse\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &position);
            insert(list, data, position);
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteNode(list, position);
            break;
        case 3:
            reverse(list);
            printf("Reversed List: ");
            displayReversed(list);
            reverse(list);
            break;
        case 4:
            printf("Linked List: ");
            display(list);
            break;
        case 5:
            printf("Exiting program\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
