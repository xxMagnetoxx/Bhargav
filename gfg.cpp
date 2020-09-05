#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define f(i, a, b) for(int i=a; i<b; i++)
#define fr(i, a, b) for(int i=a; i>=b; i--)
#define l long int
#define endl '\n'
#define pb push_back
using namespace std;
vector<int> g[10001];
int vis[10001];

void dfs(int v)
{

	cout<<v<<" ";
	vis[v]=1;
	
	for(int child : g[v])
	if(!vis[child]) dfs(child);
	
	
}
int main()
{
FAST
int tc;
cin>>tc;
while(tc--)	
{
	int n,e,i;
	int a,b;
	cin>>n>>e;
	for(i=1;i<=n;i++) g[i].clear(),vis[i]=0;
	
	for(i=1;i<=e;i++)
	{
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	dfs(0);
	cout<<endl;
}
}
