#include<bits/stdc++.h>
using namespace std;

void primAlgo(vector<pair<int , int>> adj[] , int N){
    
    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
    {
        parent[i] = -1;
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < N-1 ; count++)
    {
        int mini = INT_MAX , u;

        for (int v = 0; v < N; v++)
        {
            if(mstSet[v] == false && key[v] < mini){
                mini = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        for(auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;

            if(mstSet[v] == false && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
        
    }

    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << "--" << i << "\n";
    }
    
}

void optimisedPrim(vector<pair<int , int>> adj[] , int N){

    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
    {
        parent[i] = -1;
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int >> > pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0 , 0});

    for (int count = 0; count < N-1 ; count++)
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for(auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;

            if(mstSet[v] == false && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v] , v});
            }
        }
        
    }

    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << "--" << i << "\n";
    }
    
}

int main()
{
    int N , M;
    cin >> N >> M;

    // Undirected Weighted Graph 0-based indexing
    vector<pair<int , int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u , v , wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v , wt});
        adj[v].push_back({u , wt});
    }

    cout << "\nPRIMS ALGO: " << endl;
    primAlgo(adj , N);
    cout << endl << "OPTIMISED PRIMS ALGO: " << endl;
    optimisedPrim(adj , N);
    return 0;
}

// Input

// 5 6
// 0 1 2
// 1 2 3
// 2 4 7
// 1 4 5
// 1 3 8
// 0 3 6