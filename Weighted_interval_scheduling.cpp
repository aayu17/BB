#include <iostream>
#include <algorithm>
using namespace std;

struct Job
    {
        int start;
        int finish;
        int profit;
    };


bool compare(Job a, Job b)
{
    return a.finish< b.finish;
}

int calcNotOverlappingJob(int n, Job arr[])
{
    if(n==0)
        return 0;
    int result = 0;
    int s = arr[n].start;
    int i=n;

        while(i>0)
        {
            if(arr[i-1].finish<=s)
            {
                result++;       
            }
            i--;
        }
    return result;
}

int weightedIntervalSchedulingDP(Job j[],int n)
{   
    int dp[3][n+1];

    for(int i=0; i<3; i++)
    {
        dp[i][0] = 0;
    }
    
    for(int i=1; i<=n; i++)
    {
        dp[0][i] = j[i-1].profit;
    }

    for(int i=1;i<=n;i++)
    {
        dp[1][i]= calcNotOverlappingJob(i-1, j);
    }

    for(int i=1;i<=n;i++)
    {
        dp[2][i]= max(dp[0][i]+ dp[2][dp[1][i]], dp[2][i-1]);
    }
    cout<<endl;   
    return dp[2][n];
}

int main()
{
    int n;
    cout<<"Enter the number of jobs: ";
    cin >> n;
    Job jobs[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the start time and finish time and profit of job "<<i+1<<": ";
        cin>>jobs[i].start>>jobs[i].finish>>jobs[i].profit;
        cout<<endl;
    }
    sort(jobs, jobs + n, compare);
    cout<<weightedIntervalSchedulingDP(jobs, n);
}