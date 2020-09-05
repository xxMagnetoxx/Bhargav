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


void transpose(int V, vector<int> adj[], vector<int> transpose_adj[]) {
    for (int u = 0; u < V; u++)
        for (auto v : adj[u])
            transpose_adj[v].push_back(u);
}

stack<int> s;

int dfs(vector<int> adj[], bool *visited, int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (visited[v] == 0)
            dfs(adj, visited, v);
    }
}

int fillorder(vector<int> adj[], bool *visited, int u) {
    visited[u] = true;
    for (auto v : adj[u])
        if (visited[v] == 0)
            fillorder(adj, visited, v);
    s.push(u);
}

int kosaraju(int V, vector<int> adj[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            fillorder(adj, visited, i);

    vector<int> transpose_adj[V];
    transpose(V, adj, transpose_adj);

    for (int i = 0; i < V; i++)
        visited[i] = false;

    int ans = 0;
    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        if (!visited[temp]) {
            dfs(transpose_adj, visited, temp);
            ans++;
        }
    }

    return ans;
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
	cout<<kosaraju(a,adj)<<endl;
	
	return 0;
}
