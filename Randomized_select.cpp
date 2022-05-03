#include <bits/stdc++.h>
using namespace std;


//Randomized Partition
int randomized_partition(int arr[], int start, int end)
{
    int pivotIndex = start + rand() % (end-start+1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[end]);
    pivotIndex = end;
    int i = start -1;

    for(int j=start; j<=end-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[pivotIndex]);  
    return i+1;
}


//Randomized Select
int randomized_select(int arr[], int start, int end, int i)
{
    if(start == end)
    {
        return arr[start];
    }

    if(start < end)
    {
        int mid = randomized_partition(arr, start, end);
        int k = mid - start + 1;
        if(i == k)
        {
            return arr[mid];
        }
        else if(i < k)
        {
            return randomized_select(arr, start, mid-1, i);
        }    
        else 
        {
            return randomized_select(arr, mid+1, end, i-k);
        }
    }
}


//Main Function
int main()
{
    int a[] = {7,2,4,1,8,5,10};
    int pos = randomized_select(a,0,6,5);
    cout<<"Position is: "<<pos<<endl;    
    return 0;
}
