#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define f(i, a, b) for(int i=a; i<b; i++)
#define fr(i, a, b) for(int i=a; i>=b; i--)
#define l long int
#define pb push_back
#define endl '\n'
using namespace std;
 
vector <int> g[100001];
int w[100001];
//int vis[100001];
int dfs(int v,int i)
{
	int wchild=0;
	
	for(int child : g[v])
	{
		if(child != i)
		wchild=max(dfs(child ,v),wchild);

	}
return (w[v]+wchild);
}
 
int main()
{
int T;
cin>>T;	
while(T--)
{
	
l n,i; 
cin>>n;
 w[100001]={0};
 
 for(i=1;i<=n;i++)
 cin>>w[i];
 
 int a,b;
 
for(i=1;i<=n-1;i++)
 {
 	cin>>a>>b;
 	g[a].pb(b);
 	g[b].pb(a);
}
 for(i=1;i<=n;i++)
 {
 
 	int mxc=dfs(i,-1);
 	
 	cout<<mxc<<" ";
 }
 
 
 
}
 
} 

