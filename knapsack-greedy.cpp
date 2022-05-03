//0-1 KnapSack using greedy approach

#include<bits/stdc++.h>
using namespace std;

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


    //Profit Weight Ratio
    float profit_weight[n];
    for(int i=0;i<n;i++)
    {
        profit_weight[i]=(float)profit[i]/weight[i];
    }    
    cout<<"\nProfit/Weight of each item: \n";
    for(int i=0;i<n;i++)
    {
        cout<<profit_weight[i]<<"\n";
    }


    //Capacity of knapsack
    int capacity;
    cout<<"\nEnter the capacity of the knapsack: ";
    cin>>capacity;

    
    //Sort the profit/weight array in descending order
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(profit_weight[i]<profit_weight[j])
            {
                swap(profit_weight[i],profit_weight[j]);
                swap(profit[i],profit[j]);
                swap(weight[i],weight[j]);
            }
        }
    }


    //Sorted Profit/Weight Ratio
    cout<<"\nSorted Profit/Weight of each item: \n";
    for(int i=0;i<n;i++)
    {
        cout<<profit_weight[i]<<"\t";
    }

    
    //Greedy Approach
    float total_profit=0.0;
    float X[n] = {0.0};
    for (int i = 0; i < n; i++)
    {
        if (capacity > 0 && weight[i] <= capacity)
        {
            X[i] = 1.0;
            capacity = capacity - weight[i];
            total_profit = total_profit + X[i] * profit[i];
        }
        else
        {
            break;
        }
    }

    cout<<"Maximum Profit is: "<<total_profit<<"\n";
    return 0;   
}