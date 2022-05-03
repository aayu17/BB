//0-1 Knapsack problem using dynamic programming
#include<bits/stdc++.h>
using namespace std;


//Function to calculate the maximum value that can be obtained
int max(int x, int y)
{
    return (x > y) ? x : y;
}


//Knapsack function
int knapSack(int capacity, int weight[], int profit[], int n)
{
    int i, wt;
    int K[n + 1][capacity + 1];
    for (i = 0; i <= n; i++)
    {
        for (wt = 0; wt <= capacity; wt++)
        {
            if (i == 0 || wt == 0)
                K[i][wt] = 0;
            else if (weight[i - 1] <= wt) 
                K[i][wt] = max(profit[i - 1] + K[i - 1][wt - weight[i - 1]], K[i - 1][wt]);  
            else
                K[i][wt] = K[i - 1][wt];
        }
    }
    return K[n][capacity];
}


//Main function
int main()
{
    //Number of items
    int n;
    cout<<"\nEnter the number of items: ";
    cin>>n;


    //Input the weight and profit of each item
    int profit[n];
    int weight[n];
    cout<<"\nEnter the profit and weight of each item: \n";
    for(int i=0;i<n;i++)
    {
        cin>>profit[i]>>weight[i];
    }


    //Capacity of knapsack
    int capacity;
    cout<<"\nEnter the capacity of the knapsack: ";
    cin>>capacity;


    cout<<"\nThe total profit is: "<<knapSack(capacity,weight,profit,n);
    return 0;
}