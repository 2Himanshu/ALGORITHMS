#include<stdio.h>
#define max  100

int ans[max];
int findMinCoins(int coins[], int size, int value)
{
    int i, j, count = 0;
    for (i = 0; i < size; ++i) 
    {
        for ( j = i + 1; j < size; ++j) 
        {
            if (coins[i] < coins[j]) 
            {
                int a = coins[i];
                coins[i] = coins[j];
                coins[j] = a;
            }
        }
    }
    printf("The numbers arranged in descending order are given: ");
    for (i = 0; i < size; ++i) 
        printf("%d ", coins[i]);
    for (i = 0; i < size; i++)
    {
        // take as much from coins[i]
        while (value >= coins[i])
        {
            // after taking the coin, reduce the value.
            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if (value == 0)
            break;
    }

    return count;
}

void main()
{
    int coins[] = {20,10,25,5};
    int value = 40, i;

    //find the size of the coins array
    int size = sizeof(coins)/sizeof(coins[0]);

    int MinCount = findMinCoins(coins,size,value);

    printf("\nTotal Coins Needed = %d ",MinCount);

    printf("\nCoins are: ");
    for(i = 0; i < MinCount; i++)
        printf("%d ", ans[i]);
}
