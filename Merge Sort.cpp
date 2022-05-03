#include <bits/stdc++.h>
using namespace std;

//Merge
int merge(int arr[],int starting,int mid,int ending,int &comparisons)
{ 
    int a[ending-starting+1];
    int i=starting,j=mid+1,k=0;
    while (i<=mid && j<=ending)
    {
        if (arr[i]<=arr[j])
        {
            a[k]=arr[i];
            i++;
            comparisons++;
        }
        else
        {
            a[k]=arr[j];
            j++;
            comparisons++;
        }
        k++;
    }   
    while (i<=mid)
    {
        a[k]=arr[i];
        i++;
        k++;
    }
    while (j<=ending)
    {
        a[k]=arr[j];
        j++;
        k++;
    }
    for (int i=0;i<k;i++)
    {
        arr[starting+i]=a[i];
    }
    return comparisons;
}


//Merge Sort
int mergeSort(int arr[],int starting ,int ending)
{
    if(starting<ending)
    {
        int comparisons=0;
        int mid = (starting+ending)/2;
        mergeSort(arr,starting,mid);  //10 7 8
        mergeSort(arr,mid+1,ending);  //9 1 5
        merge(arr,starting,mid,ending,comparisons);
        return comparisons;
    }
    return 0;
}

//Random Array Generator
int randomArrayGenerator(int s)
{
    int comparisons;
    int a[s];

    //Generate Random Array
    for (int i = 0; i < s; i++)
    {
        a[i] = (rand() % 100);
    }
    
    comparisons = mergeSort(a,0,s-1);
    return comparisons;
}

//Print Array
void printArray(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Main function
int main()
{
    // int arr[] = {10,7,8,9,1,5};
    // int n = sizeof(arr)/sizeof(arr[0]);
    int start = 30, end = 1000, interval = (end-start)/100,count=0;
    for (int i = start; i < end && count < 100; i += interval)
    {
        fstream fout;
        int comparisons = randomArrayGenerator(i);
        fout.open("MergeSort_Comparisons.csv", ios::out | ios::app);
        fout<<i<<","<<comparisons<<endl;
        comparisons = 0;
        count++;
    }
    // mergeSort(arr, 0, n-1);
    // printArray(arr, n);
    return 0;
}