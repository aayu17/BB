#include <bits/stdc++.h>
using namespace std;


//Function to get sum of vector set
int setSum(const vector<int> &v)
{
    int vsum = 0;
    for (int i = 0; i < v.size(); i++)
        vsum += v[i];
    return vsum;
}


//Function to display vector set
void displaySet(const vector<int> &v)
{
    cout << "{ ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "}" << endl;
}


//Function to get the subset with maximum number of elements with sum equal to given sum.
void subsetSum(int set[], int size, int sum, vector<int> &v)
{
    if (size == 0 || sum == 0)
    {
        return;
    }
    if (set[size - 1] <= sum)
    {
        sum -= set[size - 1];
        v.push_back(set[size - 1]);
        subsetSum(set, size - 1, sum, v);
    }
}


//Main Function
int main()
{
    int set[] = {34, 12, 5, 2, 8, 11, 66};
    int size = sizeof(set) / sizeof(set[0]);
    int sum = 15;

    vector<int> v;
    sort(set, set + size, greater<int>()); // 66 34 12 11 8 5 2
    subsetSum(set, size, sum, v);

    if (sum == setSum(v))
    {
        cout << "Subset will be : ";
        displaySet(v);
    }
    else
        cout << "Subset sum not available for given sum";
}