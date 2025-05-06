//
// Created by Mohammed on 5/5/2025.
//
/*
Write a C program to implement a menu-driven application that uses a doubly linked list to perform the following operations:



Operations:

Create and Insert: Add a number to the doubly linked list.
Delete: Remove a specific number from the doubly linked list.
Display: Print the elements of the doubly linked list in order.
Reverse: Reverse the order of the doubly linked list.
Exit: The program should terminate when the user chooses this option.

*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void insert(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    //struct Node *temp = head;
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(head==NULL){
        newNode->prev = NULL;
        head = tail = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        //tail -> next = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }
}
void display(){
    struct Node *temp = head;
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    //printf("Current List:");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void remov(int data){
    struct Node* temp = head;
    while(temp!= NULL && temp->data != data){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("%d not found\n",data);
        return;
    }
    if(temp==head){
        head = temp->next;
        if(head!=NULL) head -> prev = NULL;
    }
    else if(temp==tail){
        tail = temp->prev;
        if(tail != NULL) tail->next = NULL;
    }
    else{
        temp->prev->next = temp->next;
        temp->next ->prev = temp->prev;
    }
    free(temp);
    return;
    printf("%d not found\n",data);
    printf("\n");
}
void reverse(){
    if(head==NULL || head->next==NULL){
        return;
    }
    struct Node *temp = NULL;
    struct Node *current = head;
    while(current!=NULL){
        temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;
    }
    if(temp != NULL){
        head = temp->prev;
    }
}
int main() {
    int n, ch;
    do {
        printf("Operations on doubly linked list\n");
        printf("1.Insert\n2.Remove\n3.Display\n4.Reverse\n0.Exit\n");
        printf("Enter Choice 0-4: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter number: ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            printf("Enter number to delete: ");
            scanf("%d", &n);
            remov(n);
            break;
        case 3:
            display();
            break;
        case 4:
            reverse();
            printf("List reversed\n");
            break;
        }
    } while (ch != 0);
    return 0;
}
