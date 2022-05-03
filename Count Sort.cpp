#include<bits/stdc++.h>
using namespace std;


//CountSort
void countSort(int a[],int n)
{
    int b[n];    //Output array
    int k = 0;   //K is the maximum value in the array  
    
    //Largest element in array
    for(int i=0;i<n;i++)
    {
        if(a[i]>k)
        {
            k = a[i];
        }    
    }

    //Count array
    int count[k+1] = {0};

    //Frequency of numbers in array
    for(int i=0; i<n; i++)
    {
        ++count[a[i]];
    }

    //Calculating the location 
    for(int i=1; i<=k; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    //Reducing the value in count array and storing at the index of b array
    for(int i = n-1; i>=0; i--)
    {
        b[--count[a[i]]] = a[i];
    }

    //Copying the sorted array to the original array
    for(int i=0; i<n; i++)
    {
        a[i] = b[i];
    }
}


//Print array
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//Main function
int main()
{
    //int arr[] = {1,8,5,4,7,9,6,3,2,1,10,11,15,14};
    // int arr[] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr, n);
    printArray(arr, n);
}