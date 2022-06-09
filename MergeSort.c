#include<stdio.h>
#include<conio.h>
#define MAX 10
void merge(int x[], int lb1, int ub1, int ub2)
{
	int i, j, k, temp[MAX];
	i = lb1;
	j = ub1 + 1;
	k = 0;
	while(i<=ub1 && j<=ub2) // Check kar jabh tak values hai dono array mein..tabhtak...
	{
		if(x[i] < x[j])
			temp[k++] = x[i++];
		else
			temp[k++] = x[j++];
	}
	// Check kar if koi array empty hua..if hua toh directly copy kar items in temp array
	while(i<=ub1)
		temp[k++] = x[i++];
	while(j<=ub2)
		temp[k++] = x[j++];

	for (i = lb1, k=0;  i<=ub2; i++, k++)
		x[i] = temp[k];
}
void mergeSort(int x[], int lb, int ub)
{
	int mid;
	if(lb < ub)
	{
		mid = (lb+ub)/2;
		mergeSort(x, lb, mid);
		mergeSort(x, mid+1, ub);
		merge(x, lb, mid, ub);
	}
}

void main()
{
	int arr[MAX], n, i;
	clrscr();
	//Accepting the array values
	printf("\nEnter the number of elements you want to insert: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\nPease enter any Number: ");
		scanf("%d", &arr[i]);
	}
	// Displaying the contents inside
	printf("\nUnsorted Array: \n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	mergeSort(x, 0, n-1);
	printf("\nSorted Array: \n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}	
	getch();
}