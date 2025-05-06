//
// Created by Mohammed on 5/5/2025.
//
#include<stdio.h>
void main() {
    int a[20], i, n, j, large, index;
    printf("Enter value of n : ");
    scanf("%d", &n);
    // Write the code to read an array elements
    for(int i = 0; i < n; i++) {
        printf("Enter element for a[%d] : ",i);
        scanf("%d",&a[i]);
    }
    printf("Before sorting the elements in the array are\n");
    // Write the code to print the given array elements before sorting
    for(int i=0;i<n;i++) printf("Value of a[%d] = %d\n",i,a[i]);
    for(int i=0,largest=a[0],max=0;i<n-1;i++,largest=a[0],max=0) {
        for(int j=0;j<n-i;j++) if(a[j]>largest) {
            largest=a[j];
            max=j;
        }
        a[max] = a[n-i-1];
        a[n-i-1] = largest;
    }
    // Write the code for selection sort largest element method
    printf("After sorting the elements in the array are\n");
    // Write the code to print the given array elements after sorting
    for(int i=0;i<n;i++) printf("Value of a[%d] = %d\n",i,a[i]);
}