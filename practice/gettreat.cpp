#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define len(s) s.length()
#define forp(i,a,b) for( i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define ct ll tc; cin>>tc; while(tc--)
typedef long long  ll;
typedef double  db ;
using namespace std;

const ll maxn=1e5+1;

vector<ll> g[maxn];

ll n,a[maxn],in[maxn],out[maxn];
void dfs1(ll i,ll p){
	in[i]=a[i];
	ll bc=0;
	for(ll x:g[i]){
		if(x==p) continue;
		dfs1(x,i);
		bc=max(bc,in[x]);
	}
	in[i]+=bc;
}
void dfs2(ll i,ll p){
	ll m1=-1,m2=-1;
	for(ll x:g[i]){
		if(x==p) continue;
		if(in[x]>m1) m2=m1,m1=in[x];
		else if(in[x]>m2) m2=in[x];
	}
	for(ll x:g[i]){
		if(x==p) continue;
		ll tu=m1;
		if(in[x]==m1) tu=m2;
		out[x]=a[x]+max(out[i],a[i]+tu);
		dfs2(x,i);
	}
}
int main(){
	
	FIO;
	ct{
		cin>>n;
		rep(i,n){
			g[i]={}; cin>>a[i]; in[i]=out[i]=0; 
		}
		rep(i,n-1){
			ll x,y; cin>>x>>y; x--,y--;
			g[x].pb(y); g[y].pb(x);
		}
		dfs1(0,-1);
		out[0]=a[0];
		dfs2(0,-1);
		rep(i,n) cout<<max(in[i],out[i])<<" ";
		cout<<"\n";
	}
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
