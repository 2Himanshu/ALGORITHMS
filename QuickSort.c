#include<stdio.h>
#include<conio.h>
#define MAX 10
int partition(int x[], int lb, int ub) {
    int pivot, down, up, temp;
    pivot = x[lb];
    down = lb;
    up = ub;
    while (down < up) {
        while (x[down] <= pivot && down < ub)
            down++;
        while (x[up] > pivot)
            up--;
        if (down < up) {
            temp = x[down];
            x[down] = x[up];
            xp[up] = temp;
        }
    }
    x[lb] = x[up];
    x[up] = pivot;
    return up;
}

void quick(int x[], int lb, int ub) {
    int index;
    if (lb >= ub)
        return;
    index = partition(x, lb, ub);
    quick(x, lb, index - 1); // sort left part
    quick(x, index + 1, ub); // sort right part
}

void main() {
    int x[MAX], n, i;
    clrscr();
    //Accepting the array values
    printf("\nEnter the number of elements you want to insert: ");
    scanf("%d", & n);
    for (i = 0; i < n; i++) {
        printf("\nPease enter any Number: ");
        scanf("%d", & x[i]);
    }
    // Displaying the contents inside
    printf("\nUnsorted Array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    quick(x, 0, n - 1);
    printf("\nSorted Array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    getch();
}