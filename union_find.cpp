/*	A C++ class for implementing Disjoint Set Operations
 *
 *	Author: Rohan Khanna
 *	Language: C++
 *  	Usage: Just include the class' code in your application. The main() function is just for demo purposes.
 *  	Date: 19th June 2015
 */

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
	/* size[i]   -> stores the size of the subtree rooted at index i.
	 * parent[i] -> stroes the index of the component representative.
	 * count	 -> stores the number of connected components.
	 */
	 
	int *size,*parent,count;	

	public:

	UnionFind(int n)
	{
		size   = new int[n];
		parent = new int[n];
		count  = n;

		for(int i=0;i<n;i++)
		{
			parent[i] = i;
			size[i] = 1;
		} 
	}

	~UnionFind()
	{
		delete [] size;
		delete [] parent;
	}

	/*Returns the parent of the component in which the object x lies*/
	
	int find(int x)
	{
		int root = x;

		while(root != parent[root])
		{
			root = parent[root];
		}

		while(x!=root)
		{
			int newParent = parent[x];	// Store x's current parent
			parent[x] = root;			// Update the parent of x to root;
			x = newParent;				// Move up the path
		}

		return root;
	}

	void merge(int x,int y)
	{
		int i = find(x);
		int j = find(y);

		if(i==j)
			return;			// If they are already in the same component

		if(size[i] > size[j])
		{
			parent[j] = i;
			size[i]+=size[j];
		}

		else
		{
			parent[i] = j;
			size[j]+=size[i];
		}

		count--;
	}

	bool connected(int x,int y)
	{
		return (find(x) == find(y));
	}

	int no_of_disjoint_sets()
	{
		return count;
	}	
};

int main()
{
	UnionFind UF(10);

	UF.merge(1,3);
	UF.merge(1,4);
	UF.merge(2,3);
	UF.merge(4,8);
	UF.merge(1,8);

	// cout << UF.connected(2,7) << endl;
	return 0;
}

