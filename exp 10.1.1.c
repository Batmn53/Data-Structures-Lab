//
// Created by Mohammed on 5/5/2025.
//
#include<stdio.h>
#include<conio.h>
#define MAX 10
int cost[MAX][MAX],n,e,i,j,s,d,w,ne=1;
int visited[MAX],total=0;
void prims() {
    visited[1]=1;
    int min,u,v;
    while(ne<n){
        min=999;
        for(i=1;i<=n;i++){
            if(visited[i]==1){
                for(j=1;j<=n;j++){
                    if(visited[j]==0 && cost[i][j]<min){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        visited[v]=1;

        printf("Edge cost from %d to %d : %d\n", u,v,min );
        total+=min;
        ne++;
    }
    printf("Minimum cost of spanning tree = %d\n", total  );
}
void main() {
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    for(i=1; i<=e; i++) {
        printf("Enter source : ");
        scanf("%d", &s);
        printf("Enter destination : ");
        scanf("%d", &d);
        printf("Enter weight : ");
        scanf("%d", &w);
        if(s <= 0 || d <= 0 || s > n || d > n || w < 0 ) {
            printf("Invalid data.Try again.\n");
            i--;
            continue;
        }
        cost[s][d] = w;
        cost[d][s] = w;
    }
    for(i=1; i <= n; i++) {
        for(j=1; j<=n; j++) {
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("The edges of Minimum Cost Spanning Tree are : \n");
    prims();
}