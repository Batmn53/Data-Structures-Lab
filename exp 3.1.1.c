//
// Created by Mohammed on 5/5/2025.
//
void display(int a[15], int n) {
    for(int i = 0; i < n; i++) printf("%d ",a[i]);
    printf("\n");
}
void merge(int a[15], int l, int mid, int h) {
    int arr[h-l+1];
    for(int i=l,j=mid+1,k=0;k<=h-l;)arr[k++]=(a[i]<a[j]&&i<=mid)||(j>h)?a[i++]:a[j++];
    for(int i=l,j=0;i<=h;a[i++]=arr[j++]);
}
void splitAndMerge(int a[15], int low, int high) {
    if(low<high) {
        int mid=(low+high)/2;
        splitAndMerge(a,low,mid);
        splitAndMerge(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
//#include <stdio.h>
//#include "MergeSortFunctions.c"
void main() {
    int arr[15], i, n;
    printf("Enter array size : ");
    scanf("%d", &n);
    printf("Enter %d elements : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting the elements are : ");
    display(arr, n);
    splitAndMerge(arr, 0, n - 1);
    printf("After sorting the elements are : ");
    display(arr, n);
}