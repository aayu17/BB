#include<bits/stdc++.h>
using namespace std;

class GRAPH
{
	int no_of_vertices;	
	vector<int> *myContainer;	//Adjancency List to Store edges

	public:
	//Constructor
	GRAPH(int v)	
	{
		no_of_vertices = v;   
		myContainer = new vector < int>[no_of_vertices];
	}

	//Function to add an edge
	void AddEdge(int i, int el)	
	{
		myContainer[i].push_back(el);
	}

	//Breadth First Search
	void BFS(int source)	
	{
		queue<int> q;	

		//Visited array to check if a node is visited or not
		bool Visited[no_of_vertices] = {0};	

		Visited[source] = 1;
		q.push(source);

		vector<int>::iterator it;

		while (!q.empty())
		{
			int i = q.front();
			cout << i << "  ";
			q.pop();

			for (it = myContainer[i].begin(); it != myContainer[i].end(); ++it)
			{
				if (!Visited[*it])
				{
					Visited[*it] = true;
					q.push(*it);
				}
			}
		}
	}
};

// Main Func
int main()

{
	GRAPH g(11); //Graph with 11 vertices

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

	cout << "BFS IS: ";
	g.BFS(2);

	return 0;
}