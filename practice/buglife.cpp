#include<bits/stdc++.h>
#define l long 
#define pb push_back
//#define vector
using namespace std;

int col[2001];
int vis[2001];
vector <int> g[2001];

bool dfs(int v,int c)
{
	
	vis[v]=1;
	col[v]=c;
	for(int child : g[v])
	{
		if(vis[child] == 0)
		{
			bool res = dfs(child,c^1);
			if(res == false)
			return false;
		}
		else
		if(col[v] == col[child])
		return false;
	}
	
	return true;
	
}
int main()
{
	int t;
	cin>>t;
	
	for(int tc=1;tc<=t;tc++)
	{
		int n,e;
		
		cin >>n>>e;
		
	for(int i=1;i<=n;i++)
	{
	  g[i].clear(),vis[i]=0 ;
	 }
		int a,b;
	
	for(int i=1; i<=e ;i++)
	cin>>a>>b , g[a].pb(b) , g[b].pb(a);
	
	bool flag =true;
	for(int i=1;i<=n;i++)
	if(vis[i]==0)		
	{
		bool res = dfs(i,0);
		
		if(res == false)
		{
		flag = false;
	
		}
	}
	cout<<"Scenario #"<<tc<<":"<<endl;
	
	if(flag == false)
	cout<<"Suspicious bugs found!"<<endl;
	else
	cout<<"No suspicious bugs found!"<<endl;
	
}
		
}
