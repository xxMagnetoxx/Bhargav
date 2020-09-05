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

struct edge{
	int a,b,w;
};
edge ar[10001];
int par[10001];

ll MOD=1000000000000007;


bool camp(edge a,edge b)
{
	if(a.w>b.w)
	return false;

	return true;
}

int find(int a)
{
	if(par[a] == -1) return a;
	
	return par[a]=find(par[a]);
}
void merge(int a ,int b )
{
	par[a] = b;
	
}
int main()
{
FAST

int n,m,a,b,w;
cin>>n>>m;

for(int i=0;i<=n;i++)
par[i]=-1;

for(int i=0;i<m;i++)
{
	cin>>ar[i].a>>ar[i].b>>ar[i].w;
	
}
sort(ar,ar+m,camp);
int sum=0;
for(int i=0;i<m;i++)
{
	a = find(ar[i].a);
	b = find(ar[i].b);
	
	if(a!=b)
	{
		sum+=ar[i].w;
		merge(a,b);
	}
}

cout<<sum<<endl;
}







