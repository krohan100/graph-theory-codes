#include <bits/stdc++.h>
using namespace std;

class Graph{

	int V;
	list<int> *adj;

	void topological_sort_util(int v,bool visited[],stack<int> &Stack);

public:

	Graph(int v);

	void add_edge(int u,int v);

	void topological_sort();

	

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

void Graph::topological_sort_util(int v,bool visited[], stack<int> &Stack)
{
	visited[v] = true;
	list<int>::iterator it;

	for(it=adj[v].begin();it!=adj[v].end();++it)
	{
		if(!visited[*it])
		{
			topological_sort_util(*it,visited,Stack);
		}
	}

	Stack.push(v);	
}

void Graph::topological_sort()
{
	stack<int> Stack;

	bool *visited = new bool[V];

	for(int i=0;i<V;i++)
	{
		visited[i] = false;
	}  

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			topological_sort_util(i,visited,Stack);
		}
	}

	while(!Stack.empty())
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
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