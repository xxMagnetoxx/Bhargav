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

const int maxn=10; // 2^20 >= 10000(nearly)
vector <int> g[100001];
int level[1001];
int LCA[1001][maxn];
void dfs(int node , int lvl , int par)
{
	level[node] = lvl;
	LCA[node][0]=par;
	for(int child : g[node])
	{
		if(child != par)
		dfs(child , lvl+1 , node);
	}
}

void init(int n)
{
	dfs(1,0,-1);
	
	for(int i=1;i<=maxn;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(LCA[j][i-1] != -1)
			{
				int par = LCA[j][i-1];
				LCA[j][i] = LCA[par][i-1];
			}
		}
	}
}

int getlca(int a , int b)
{
	if(level[b]<level[a])swap(a,b);
	
	int d = level[b] - level[a];
	
	while(d>0)
	{
		int i = log2(d);
		b = LCA[b][i];
		
		d-= 1<<i;
	}
	
	if(a==b)
	return a;
	
	for(int i = maxn;i>=0;i--)
	{
		if(LCA[a][i]!=-1 && LCA[a][i]!=LCA[b][i])
		a= LCA[a][i] , b=LCA[b][i];
	}
	return LCA[a][0];
}

int getdist(int a , int b)
{
	int lca = getlca(a ,b);
	return level[a] + level[b] - 2*level[lca];
}


int main()
{
//FAST

int n,a,b,q;
cin>>n;
for(int i=0;i<n-1;i++)
{
cin>>a>>b;
g[a].pb(b);
g[b].pb(a);
}

for(int i=1;i<=n;i++)
for(int j=1;j<=maxn;j++)
LCA[i][j]=-1;


init(n);

cin>>q;

while(q--)
{
	cin>>a>>b;
	cout<<getdist(a,b)<<endl;
}

}







