#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define f(i, a, b) for(int i=a; i<b; i++)
#define fr(i, a, b) for(int i=a; i>=b; i--)
#define l long int
#define endl '\n'
#define pb push_back
#define pf pop.front()
using namespace std;

vector<int>g[1001];
bool vis[1001];
int in[1001];
int low[1001];
int timer=0;
int bridge=0;
void dfs(int node , int par)
{
	vis[node] =1;
	in[node] = low[node] =timer;
	timer++;
	
	for(int child : g[node])
	{
		if(child == par) continue;
		
		if(vis[child] == 1)
		{
			// this edge is back edge
			low[node] = min(low[node] , in[child]);
		}
		
		else
		{
			// this my be front edge if low[child] > in[node]
			
			dfs(child , node);
			
			if(low[child] > in[node])
			{
				cout<<node<<" "<<child<<" Is Bridge"<<endl;
				bridge++;
			}
			
			low[node] = min(low[child] , low[node]);
		}
	}

}


ll MOD=1e9+7;
int main()
{
FAST
int e,n,a,b;
cin>>n>>e;

for(int i=0;i<e;i++)
{
	cin>>a>>b;
	g[a].pb(b);
	g[b].push_back(a);
	
}

dfs(1,-1);
cout<<"There are "<<bridge<<"Bridges"<<endl;
}







