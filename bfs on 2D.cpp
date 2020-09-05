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

int vis[1001][1001];
int dist[1001][1001];
//memset(dist, -1, sizeof dist); 
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int m,n;
l qe;

bool isvalid(int x , int y)
{
	if(x>m-1 || y>n-1 || x<0 || y<0)
	return false;
	if(vis[x][y] ==1)
	return false;
	return true;
}

void bfs(int sx,int sy)
{
queue<pair<int , int> >q;
q.push({sx,sy});
dist[sx][sy] = 0;

vis[sx][sy]=1;
while(!q.empty())
{
	
int x = q.front().first;
int y = q.front().second;
int d=dist[x][y];
q.pop();
for(int i=0;i<4;i++)
{
int newx = x+dx[i];
int newy = y+dy[i];
if(isvalid(newx,newy))
{
	dist[newx][newy]=d+1;
	vis[newx][newy]=1;
	q.push({newx , newy});
}
}

}
}

int main()
{
FAST
for(int i=0;i<1001;i++)
	for(int j=0;j<1001;j++)
	dist[i][j]=-1;
	

cin>>m>>n>>qe;

int a[m][n];
char c;
for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
	cin>>c;
	if(c=='*')
	{
	vis[i][j]=1;
	}
		
	}
}
int srcx , srcy;
cin>>srcx>>srcy;
srcx--,srcy--;
bfs(srcx , srcy);
int x,y;
for(l i=0;i<qe;i++)
{
	cin>>x>>y;
x-- , y--;

	cout<<dist[x][y]<<endl;
	
}

}












