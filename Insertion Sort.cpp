#include<bits/stdc++.h>
using namespace std;

//Insertion Sort
int InsertionSort(vector<int> arr)
{
    int count = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int current  = arr[i];
        int j = i-1;
        if(current < arr[j])
        {
            while (j>=0 && current < arr[j])
            {
                arr[j+1] = arr[j];
                j--;
                count++;
            }
            count++;
        }
        else
        {
            count++;
        }
        arr[j+1] = current;
    }
    return count;
}

//Print the array
void printArray(vector<int> arr)
{
    int size = arr.size();
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

// For BestCase
void bestCase(int num_case , int min_size , int max_size)
{
    int increment = ((max_size-min_size)/num_case);
    while (min_size < max_size)
    {
        fstream fout;
        int CurrSize = min_size;
        vector<int> arr(CurrSize);

        for (int i = 0; i < CurrSize; i++)
        {
            arr[i] = (rand() % 100);
        }

        //Sorting the array in ascending order
        sort(arr.begin(),arr.end());
        printArray(arr);
        
        // int count = InsertionSort(arr);

        // //Increment the size
        // min_size+=increment;

        // fout.open("BestCase.csv", ios::app);
        // fout << arr.size() << "," << count << endl;
    }
}

//For WorstCase
void worstCase(int num_case , int min_size , int max_size)
{
    int increment = ((max_size-min_size)/num_case);
    while (min_size < max_size)
    {
        fstream fout;
        int CurrSize = min_size;
        vector<int> arr(CurrSize);

        for (int i = 0; i < CurrSize; i++)
        {
            arr[i] = (rand() % 100);
        }

        //Sorting the array in descending order
        sort(arr.begin(), arr.end(), greater <>());
        
        int count = InsertionSort(arr);

        //Increment the size
        min_size+=increment;

        fout.open("WorstCase.csv", ios::app);
        fout << arr.size() << "," << count << endl;
    }
}

//For AverageCase
void avgCase(int num_case , int min_size , int max_size)
{
    int increment = ((max_size-min_size)/num_case);
    while (min_size < max_size)
    {
        fstream fout;
        int CurrSize = min_size;
        vector<int> arr(CurrSize);

        for (int i = 0; i < CurrSize; i++)
        {
            arr[i] = (rand() % 100);
        }
        
        int count = InsertionSort(arr);

        //Increment the size
        min_size+=increment;

        fout.open("AverageCase.csv", ios::app);
        fout << arr.size() << "," << count << endl;
    }
}

//Main Function
int main()
{
    bestCase(29,30,1000);
    // worstCase(29,30,1000);
    // avgCase(60,30,1000);
    return 0;
}