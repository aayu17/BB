#include<bits/stdc++.h>
using namespace std;

class GRAPH
{
	int no_of_vertices;	
	vector<int> *myContainer;	
    bool *Visited;

	public:
	//Constructor
	GRAPH(int v)
	{
		no_of_vertices = v;
		myContainer = new vector < int>[no_of_vertices];
        Visited= new bool[no_of_vertices];

	}

	//Function to add an edge in the graph
	void AddEdge(int i, int el)
	{
		myContainer[i].push_back(el);
	}

	//Depth First Search
	void DFS(int source)	
	{
		Visited[source] = 1;
		cout<<source<<"  ";

		vector<int>::iterator it;
		for (it = myContainer[source].begin(); it != myContainer[source].end(); ++it)
		{
			if (!Visited[*it])
			{
				DFS(*it);
			}	
		}
	}
};


int main()
{
	GRAPH g(11);

	//Adding Edges
	g.AddEdge(1,2);
	g.AddEdge(1,4);
	g.AddEdge(2,1);
	g.AddEdge(2,3);
	g.AddEdge(2,8);
	g.AddEdge(2,7);
	g.AddEdge(2,5);
	g.AddEdge(3,10);
	g.AddEdge(3,9);
	g.AddEdge(3,2);
	g.AddEdge(3,4);
	g.AddEdge(4,1);
	g.AddEdge(4,3);
	g.AddEdge(5,6);
	g.AddEdge(5,7);
	g.AddEdge(5,2);
	g.AddEdge(5,8);
	g.AddEdge(6,5);
	g.AddEdge(7,2);
	g.AddEdge(7,8);
	g.AddEdge(7,5);
	g.AddEdge(8,2);
	g.AddEdge(8,5);
	g.AddEdge(8,7);
    g.AddEdge(9,3);
	g.AddEdge(10,3);

	cout << "DFS IS: ";
	g.DFS(2);
	return 0;
}