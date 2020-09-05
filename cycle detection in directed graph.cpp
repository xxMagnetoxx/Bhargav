#include <bits/stdc++.h>
//#include<stdio.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define f(i, a, b) for(int i=a; i<b; i++)
#define fr(i, a, b) for(int i=a; i>=b; i--)
#define l long int
#define endl '\n'
#define pb push_back
#define pf pop.front()

using namespace std;
bool dfs(int u, vector<char> &colour, vector<int> adj[])
{
    if(colour[u]=='w')          // If colour is intially 'w' change the colour to 'g'
    {
        colour[u]='g';
        
       // bool res;
        for(int v : adj[u])     // Traverse for its neighbouring vertices
        {
            if(dfs(v,colour,adj)==true)
                return true;
        }
        colour[u]='b';          // After successful traversal mark it as 'b'
        return false;
    }
    if(colour[u]=='g')          // If node colour come as 'g' again it is repeated, return true.
        return true;                                                                                                            
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<char> colour(V,'w');         // Mark the initial node as 'w'
    for(int i=0;i<V;i++)
    {
        if(colour[i]=='w')              // In0..0tially the node is 'w'
        {
            if(dfs(i,colour, adj))      // If node is repeated again return true from dfs
                return true;
        }
    }
    return false;
}


int main()
{
	int a,b;
	cin >> a>>b;
	int m,n;
	vector <int> adj[a];
	for(int i=0;i<b;i++)
	{
	cin>>m>>n;
	m-- , n--;
		adj[m].pb(n);
	}
	cout<<isCyclic(a,adj)<<endl;
	
	return 0;
}
