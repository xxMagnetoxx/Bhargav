#include<bits/stdc++.h>
using namespace  std;

	vector <int>g[1000];
	bool vis[1000];
//	memset(vis,false,sizeof(vis));
	int dist[1000];
	
	void dfs(int v,int d)
	{
		if(vis[v])
		return;
		vis[v]=true;
		dist[v]=d;
		for( int child : g[v])
		{
		if (!vis[child]) dfs(child , dist[v] + 1 );
		}
	}
int main()
{
	int n;
	cin>>n;
	int s=n-1,a,b;
	while(s--)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	
	int q,mn=INT_MAX,gc,ans=-1;
	
	cin>>q;
	while(q--)
	{
	cin>>gc;
	if(dist[gc] < mn)
	mn=dist[gc] , ans=gc;
	
	else if(dist[gc] == mn && gc < ans )
	ans = gc ;
	
	}
	
	cout<<ans;
}
