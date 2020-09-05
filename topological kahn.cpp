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

vector <long int>g[100001];
bool vis[100001];
int in[100001];
bool cyc=false;
vector<long int>res;

void kahn(long int n)
{
	queue<int>q;
	
	for(long int i=1;i<=n;i++)
	{
		if(in[i]==0)
		q.push(i);
	}
	while(!q.empty())
	{
		long int curr = q.front();
		res.pb(curr);
		q.pop();
		
		for(long int node : g[curr])
		{
			in[node]--;
			if(in[node] == 0)
			q.push(node);
		}
	}	
	for(long int v : res)
	cout<<v<<" ";
	
	
}
int main()
{
l n ,e,i;

cin>>n>>e;
l a,b;
for(i=1;i<=e;i++)
{
	cin>>a>>b;
	g[a].pb(b);
	in[b]++;
}
kahn(n);

}

