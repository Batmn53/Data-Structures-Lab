//
// Created by Mohammed on 5/6/2025.
//
/*
Write a C program to perform Breadth First Search (BFS) traversal on a graph.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 99

typedef struct node{
    int vertex;
    struct node* next;
}*GNODE;

// Write your code here...
int queue[MAX],front=-1,rear=-1;
void enqueue(int v){
    if(rear==MAX-1){
        printf("Queue overflow\n");
    } else {
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=v;
    }
}

int dequeue(){
    int val;
    if(front==-1||front>rear)
        return -1;
    val = queue[front];
    front++;
    return val;
}
int isEmpty(){
    return front == -1 ||front>rear;
}
GNODE graph[MAX];
int visited[MAX];
void BFS(int start){
    int v;
    GNODE p;
    visited[start]=1;
    enqueue(start);
    while(!isEmpty()){
        v = dequeue();
        printf("\n%d",v);
        for(p=graph[v];p!=NULL;p=p->next){
            if(!visited[p->vertex]){
                enqueue(p->vertex);
                visited[p->vertex]=1;
            }
        }
    }
}
void main() {
    int n, E, s, d, i, j, v;
    GNODE p, q;
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    printf("Enter no of edges: ");
    scanf("%d",&E);
    for(i=1;i<=E;i++) {
        printf("Enter source: ");
        scanf("%d",&s);
        printf("Enter destination: ");
        scanf("%d",&d);
        q=(GNODE)malloc(sizeof(struct node));
        q->vertex=d;
        q->next=NULL;
        if(graph[s]==NULL) {
            graph[s]=q;
        } else {
            p=graph[s];
            while(p->next!=NULL)
                p=p->next;
            p->next=q;
        }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("Enter Start Vertex for BFS: ");
    scanf("%d", &v);
    printf("BFS of graph: ");
    BFS(v);
    printf("\n");
}
