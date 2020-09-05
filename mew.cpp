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
vector<int>g[1009];



int main()
{
//FAST
int tc;
cin>>tc;
while(tc--)
{
int n,node,a,b;
l m;
cin>>n>>m;

 for(int i=0;i<n+3;i++)
    g[i].clear();
    
for(long int i=0;i<m;i++)
{
cin>>a>>b;
g[a].pb(b);
g[b].pb(a);
}

bool vis[1000001];
int dist[n+2];
memset(dist, -1 ,sizeof dist);
memset(vis , false , sizeof vis);

cin>>node;

queue<int>q;

q.push(node);
vis[node] = 1;
dist[node] = 0;
while(!q.empty())
{
	int curr = q.front();
	q.pop();
	for(int child : g[curr])
	{
		if(!vis[child])
		{
			vis[child] = 1;
			dist[child] = dist[curr] + 6;
			q.push(child);
		}
	}
	
}
for(int i=1;i<=n;i++)
{
	if(i != node)
	cout<<dist[i]<<" ";
}
cout<<endl;
}	
}







