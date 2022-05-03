#include <bits/stdc++.h>
using namespace std;


//Max Heapify
void maxHeapify(int arr[],int n,int i,int &comparisons)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest])  //Comparing left child with parent
    {
        largest = l;
        comparisons++;
    }
    if (r<n && arr[r]>arr[largest])  //Comparing right child with parent
    {
        largest = r;
        comparisons++;
    }
    if(largest != i)  //If parent is not largest
    {
        swap(arr[i],arr[largest]);   //Swap parent and largest
        maxHeapify(arr,n,largest,comparisons);   //Recursively call maxHeapify
    }
}


//BuildHeap
void buildHeap(int arr[],int n,int &comparisons)
{
    //This function would make heap 
    for(int i=n/2-1;i>=0;i--)  //Loop from last parent
    {
        maxHeapify(arr,n,i,comparisons);  //Call maxHeapify
    }
}


//HeapSort
void heapSort(int arr[],int n,int &comparisons)
{   
    buildHeap(arr,n,comparisons);  //Build Heap
    for(int i = n-1 ; i>0 ; i--)
    {
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0,comparisons);
    }
}


//Random Array Generator
void randomArrayGenerator(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] = (rand()%100);
    }
}


//Print Array
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//Heap Function: Average Case
void heap_random_case(int num_cases, int min_size, int max_size)
{
    fstream fout;
    fout.open("Heap_Average_Case.csv",ios::out);
    int interval = (max_size-min_size)/num_cases;
    int count = 0;

    for(int size = min_size; size < max_size && count < num_cases; size += interval,count++)
    {
        int *arr = new int[size];
        randomArrayGenerator(arr,size);
        int comparisons = 0;
        heapSort(arr,size,comparisons);
        fout<<size<<","<<comparisons<<endl;
        delete[] arr;
    }
    fout.close();
}


//Heap Function: Best Case
void heap_best_case(int num_cases, int min_size, int max_size)
{
    fstream fout;
    fout.open("Heap_Best_Case.csv",ios::out);
    int interval = (max_size-min_size)/num_cases;
    int count = 0;

    for(int size = min_size; size < max_size && count < num_cases; size += interval,count++)
    {
        int *arr = new int[size];
        randomArrayGenerator(arr,size);
        sort(arr,arr+size);  
        reverse(arr,arr+size);   //Sort the array in descending order
        int comparisons = 0;
        heapSort(arr,size,comparisons);
        fout<<size<<","<<comparisons<<endl;
        delete[] arr;
    }
}


//Heap Function: Worst Case
void heap_worst_case(int num_case, int min_size, int max_size)
{
    fstream fout;
    fout.open("Heap_Worst_Case.csv",ios::out);
    int interval = (max_size-min_size)/num_case;
    int count = 0;

    for(int size = min_size; size < max_size && count < num_case; size += interval,count++)
    {
        int *arr = new int[size];
        randomArrayGenerator(arr,size);
        sort(arr,arr+size);   //Array in ascending order
        int comparisons = 0;
        heapSort(arr,size,comparisons);
        fout<<size<<","<<comparisons<<endl;
        delete[] arr;
    }
}


//Main Function
int main()
{
    heap_random_case(100,30,1000);
    heap_best_case(100,30,1000);
    heap_worst_case(100,30,1000);
    return 0;
}