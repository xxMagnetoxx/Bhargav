#include<bits/stdc++.h>
using namespace  std;


void DFSUtil (int i, vector <int> g[], int N, bool vis[], vector <int> &res)
{
    if (vis[i]) return;//if node is visited then return 
    vis[i] = true; // if not then intiliaze as true
    res.push_back (i);
    
    for (int j : g[i])
    {
        if (!vis[j]) DFSUtil (j, g, N, vis, res);
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    bool vis[N];
    memset (vis, false, sizeof (vis)); // which intilize  false as full size of vis
    
    vector <int> res;
    for (int i = 0;i < N; i++)
    {
        if (!vis[i])
        {
            DFSUtil (i, g, N, vis, res);
        }
    }
    
    return res;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	int n,e;
	cin>>n>>e;
	vector <int> g[n];
	bool vis[n];
//	memset(vis,false,sizeof(vis));
	int u,v;
	for(int i=0;i<e;i++)
{
cin>>u>>v;
g[u].push_back(v);
g[v].push_back(u);

}
vector <int> res=dfs(g,n);
for(int i=0;i<res.size();i++)
{
	cout<<res[i]<<" ";
}
cout<<endl;
}
}
