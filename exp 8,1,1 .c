//
// Created by Mohammed on 5/5/2025.
//
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node {
    struct node *next;
    int vertex;
} *GNODE;
GNODE graph[MAX] = {NULL};

void print(int *n);
void insertVertex(int *n);
void insertEdge(int *n);
void deleteVertex(int *n);
void deleteEdge(int *n);

void insertVertex(int *n){
    (*n)++;
    graph[*n]=NULL;
    printf("Vertex inserted: %d\n",*n);
}
void insertEdge(int *n){
    int src, dest;
    printf("Enter the source vertex of the edge : ");
    scanf("%d",&src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d",&dest);
    if(src>*n|| dest > *n || src<=0 || dest <=0) {
        printf("Invalid vertex number.\n");
        return;
    }
    GNODE newNode = (GNODE)malloc(sizeof(struct node));
    newNode->vertex = dest;
    newNode->next = NULL;
    if(graph[src]==NULL)
    {
        graph[src]= newNode;
    }
    else {
        GNODE p = graph[src];
        while(p->next !=NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
    printf("After inserting edge the adjacency list is : \n");
    print(n);
}
void deleteVertex(int *n) {
    int v,i;
    printf("Enter the vertex to be deleted : ");
    scanf("%d",&v);
    if(v>*n || v<=0) {
        printf("Vertex not found.\n");
        return;
    }
    GNODE temp;
    while(graph[v]!=NULL) {
        temp = graph[v];
        graph[v] = graph[v]->next;
        free(temp);
    }
    for(i=1; i<=*n; i++) {
        if(i==v||graph[i]==NULL)continue;
        GNODE prev = NULL, curr = graph[i];
        while(curr!=NULL){
            if(curr->vertex==v) {
                if(prev==NULL) {
                    graph[i] = curr->next;
                }
                else {
                    prev -> next = curr->next;
                }
                free(curr);
                break;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    for(i=v+1; i<=*n; i++){
        graph[i-1] = graph[i];
    }
    graph[*n]=NULL;
    for(i=1; i<=*n-1;i++){
        GNODE curr = graph[i];
        while(curr!=NULL){
            if(curr->vertex >v){
                curr->vertex--;
            }
            curr = curr->next;
        }
    }
    (*n)--;
    printf("After deleting vertex the adjacency list is : \n");
    print(n);
}
void deleteEdge(int *n){
    int src,dest;
    printf("Enter the source vertex of the edge : ");
    scanf("%d",&src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d",&dest);
    if(src>*n|| dest>*n||src<=0||dest<=0){
        printf("Invalid vertex number.\n");
        return;
    }
    /*if(graph[src]==NULL){
    printf("No edges from vertex.\n");
    return;
    }*/
    GNODE curr = graph[src];
    GNODE prev = NULL;
    while(curr != NULL){
        if(curr->vertex == dest){
            if(prev==NULL){
                graph[src] = curr->next;
            }
            else{
                prev -> next = curr->next;
            }
            free(curr);
            printf("After deleting edge the adjacency list is : \n");
            print(n);
            return;
        }
        prev = curr;
        curr = curr -> next;
    }
    printf("Edge not found.\n");
}
void print(int *n){
    int i;
    for(i=1; i<= *n; i++){
        if(graph[i]!=NULL){
            printf("%d=>",i);
            GNODE temp = graph[i];
            while(temp!=NULL){
                printf("%d\t",temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}
void main() {
    int x, op;
    int N,E,s,d,i,j;
    GNODE p,q;
    printf("Enter the number of vertices : ");
    scanf("%d",&N);
    printf("Enter the number of edges : ");
    scanf("%d",&E);
    for(i=1;i<=E;i++) {
        printf("Enter source : ");
        scanf("%d",&s);
        printf("Enter destination : ");
        scanf("%d",&d);
        q=(GNODE)malloc(sizeof(struct node));
        q->vertex=d;
        q->next=NULL;
        if(graph[s]==NULL)
            graph[s]=q;
        else {
            p=graph[s];
            while(p->next!=NULL)
                p=p->next;
            p->next=q;
        }
    }
    while(1) {
        printf("1.Insert vertex 2.Insert edge 3.Delete vertex 4.Delete edge 5.Print adjacency list 6.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op) {
        case 1:
            insertVertex(&N);
            break;
        case 2:
            insertEdge(&N);
            break;
        case 3:
            deleteVertex(&N);
            break;
        case 4:
            deleteEdge(&N);
            break;
        case 5:
            print(&N);
            break;
        case 6:
            exit(0);
        }
    }
}