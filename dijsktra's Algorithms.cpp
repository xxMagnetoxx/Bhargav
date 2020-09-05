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
#define INF INT_MAX
using namespace std;

vector <pair<int , int >>g[10001];

int main()
{
FAST

int n , m , a,b,w;
cin>>n>>m;
f(i,0,m)
{
	cin>>a>>b>>w;
	g[a].pb({b,w});
	g[b].pb({a,w});
}

priority_queue<pair<int , int >, vector<pair<int , int>>,greater<pair<int , int>> >pq; // min_heap :  top element is least by weight

//priority_queue<int> //by default max heap :  (top of element is max)


vector <int>dist(n+1 ,INF);

pq.push({0,1});
dist[1]=0;

while(!pq.empty())
{
	int curd = pq.top().first;
	int curr = pq.top().second; //we can optimised it - label outdated or not 
	pq.pop();
	
	for(pair<int , int >edge : g[curr] )
	{
		if(curd + edge.second < dist[edge.first])
		{
			dist[edge.first] = curd + edge.second; 
			pq.push({dist[edge.first],edge.first });
		}
	}
}
for(int i=1;i<=n;i++)
{
	cout<<dist[i]<<" ";
}

}

/*
6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5
*/





