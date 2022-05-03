#include<bits/stdc++.h>
using namespace std;


//CountSort
void countSort(int a[],int n,int pos)
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
        ++count[(a[i]/pos)%10];
    }

    //Calculating the location 
    for(int i=1; i<=k; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    //Reducing the value in count array and storing at the index of b array
    for(int i = n-1; i>=0; i--)
    {
        b[--count[(a[i]/pos)%10]] = a[i];
    }

    //Copying the sorted array to the original array
    for(int i=0; i<n; i++)
    {
        a[i] = b[i];
    }
}


//Radix Sort
void radixSort(int a[], int n)
{
    int maximum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>maximum)
        {
            maximum = a[i];
        }    
    }
    
    //Taking digits of ones, tens, hundreds, thousands, etc.
    for(int pos=1;maximum/pos>0;pos*=10)
    {
        countSort(a,n,pos);
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
    int arr[] = {88,758,22,33,44,55,989};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    printArray(arr, n);
}