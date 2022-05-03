#include<bits/stdc++.h>
using namespace std;

//Interval Scheduling
int intervalScheduling(int n, int start[], int finish[])
{
    set<int> A;
    int i=0;
    A.insert(i);
    for(int j = 1; j < n; j++)
    {
        if(finish[i] <= start[j])
        {
            A.insert(j);
            i=j;
        }  
    }
    
    cout<<"The intervals are: ";
    for (auto it = A.begin(); it !=A.end(); ++it)
    {
        cout<<"["<<start[*it]<<" "<<finish[*it]<<"]"<<" ";
    }
}


//Main Function
int main()
{
    int jobs = 5;
    int start[] = {1, 2, 3, 4, 5};
    int finish[] = {3, 4, 5, 6, 7};
    intervalScheduling(jobs, start, finish);
    return 0;
}
