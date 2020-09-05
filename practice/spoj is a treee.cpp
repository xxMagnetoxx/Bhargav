#include<bits/stdc++.h>
using namespace  std;

	vector <int>g[10001];
	bool vis[10001];
//	memset(vis,false,sizeof(vis));
//	int dist[1000];

	void dfs(int v)
	{
		
		
		vis[v]=1;
		for( int child : g[v])
		{
		if (!vis[child]) dfs(child);
		}
		
	}
int main()
{
	int n,e;
	cin>>n>>e;
	int a,b;
	
	int s=e;
	while(s--)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int cccount=0;
	for(int i=0;i<n;i++)
	if(vis[i+1]==0)
	dfs(i+1) , cccount++;
	

	if(cccount==1 && n==e+1)
	cout<<"YES";
	else
	cout<<"NO";
}
