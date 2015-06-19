/*	A C++ program for implementing topological sort.
 *
 *	Author: Rohan Khanna
 *	Language: C++
 *  Usage: Just create a graph object, populate its edges and call the topological sort method.
 *  Date: 19th June 2015
 */



#include <bits/stdc++.h>
using namespace std;

/*
 * The Graph class
 */

class Graph{

	private:
		int V;				// Number of vertices
		list<int> *adj;		// Adj List of the Graph object

		// Topological sort utility function (this helper makes the recursive call)
		void topological_sort_util(int v,bool visited[],stack<int> &s); 	

	public:
		Graph(int v);					// Constructor for the class
		void add_edge(int u,int v);		// Adding an edge from u->v
		void topological_sort();		// Topological sort method 
};

Graph::Graph(int v)
{
	this->V   = v;
	this->adj = new list<int> [v]; 
}

void Graph::add_edge(int u,int v)
{
	adj[u].push_back(v);
}

void Graph::topological_sort_util(int v,bool visited[], stack<int> &s)
{
	visited[v] = true;
	list<int>::iterator it;

	for(it=adj[v].begin();it!=adj[v].end();++it)
	{
		if(!visited[*it])
		{
			topological_sort_util(*it,visited,s);
		}
	}

	s.push(v);	
}

void Graph::topological_sort()
{
	stack<int> s;
	bool *visited = new bool[V];

	for(int i=0;i<V;i++)
	{
		visited[i] = false;
	}  

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			topological_sort_util(i,visited,s);
		}
	}

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main()
{
	Graph g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph \n";
    g.topological_sort();
 
    return 0;
}