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
int vis[100001];
string bfs(int v, string s1,char *s)
{
	queue<int>q;
	q.push(v);
		if(!vis[v])
		for(int i=0;s1[i]!='\0';i++)
		{
		if(s1[i] == s[v])
		s1[i]='0';
		}
	vis[v]=1;
	while(!q.empty())
	{
	int curr = q.front();
	q.pop();
	
	for(int child : g[curr])
	{
		if(vis[child] == 0)
		{
		
		q.push(child);
		vis[child]=1;
			
		}
		
	}
	}
	return s1;
}

int main()
{
l n,q,i; 
cin>>n>>q;
 char s[100001];

 for(i=0;i<n;i++)
 cin>>s[i];
 
 l a,b;
// string s;
 for(i=1;i<=n-1;i++)
 {
 	cin>>a>>b;
 	g[a].pb(b);
 	g[b].pb(a);
 }
 
 while(q--)
 {
 	vis[100001]={0};
 	string s1;
	cin>>a>>s1;
	
 s1=bfs(a,s1,s);
 	l cnt=0;
 	for(i=0;s1[i]!='\0';i++)
 	{
 		if(s1[i] != '0')
 		cnt++;
	 }
	 cout<<cnt<<endl;
 }
} 
