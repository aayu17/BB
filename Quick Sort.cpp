#include <bits/stdc++.h>
using namespace std;

//Partition
int partition(int arr[],int low,int high,int &comparison)
{
    int pivot = arr[low];
    int i = low;  //index       
    int j = high; //index
    
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
            comparison++;
        }
        while(arr[j]>pivot)
        {
            j--;
            comparison++;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
            comparison++;
        }
    }
    swap(arr[j],arr[low]);
    return j;
}

//Partition  (2nd way)
// int partition(int arr[], int low, int high, int &comparison)
// {
//     int pivot = arr[high];
//     int i = low - 1;
//     for(int j = low; j < high; j++) 
//     {
//         if (comparison++, arr[j] <= pivot) 
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return i + 1;
// }


//QuickSort
void quickSort(int arr[],int low,int high,int &comparison)
{
    if(low<high)
    {
        int pivot = partition(arr,low,high,comparison);
        quickSort(arr,low,pivot-1,comparison);
        quickSort(arr,pivot+1,high,comparison);
    }
    else
    return;
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


//QuickSort Average Case
void quick_average_case(int num_cases,int min_size,int max_size)
{
    fstream fout;
    fout.open("QuickSort_average_case.csv", ios::out | ios::app);
    int interval = (max_size-min_size)/num_cases;
    int count = 0;
    for(int size = min_size; size < max_size && count < num_cases; size += interval,count++)
    {
        int *average_array = new int[size];
        randomArrayGenerator(average_array,size);
        int comparison = 0;
        quickSort(average_array,0,size-1,comparison);
        fout << size << "," << comparison << endl;
        delete[] average_array;
    }
    fout.close();
}


//QuickSort Worst Case
void quick_worst_case(int num_cases,int min_size,int max_size)
{
    fstream fout;
    fout.open("QuickSort_worst_case.csv", ios::out | ios::app);
    int interval = (max_size-min_size)/num_cases;
    int count = 0;

    //Ascending Order
    for(int size = min_size; size < max_size && count < num_cases; size += interval,count++)
    {
        int *worst_array = new int[size];
        randomArrayGenerator(worst_array,size);

        //Descending Order
        sort(&worst_array[0],&worst_array[size],greater<int>());
        int comparison = 0;
        quickSort(worst_array,0,size-1,comparison);
        fout << size << "," << comparison << endl;
        
        comparison = 0;

        //Ascending Order
        quickSort(worst_array,0,size-1,comparison);
        fout << size << "," << comparison << endl;
        delete[] worst_array;
    }
    fout.close();
}


//Main Function
int main()
{
    quick_average_case(100,30,1000);
    quick_worst_case(50,30,1000);
    return 0;
}