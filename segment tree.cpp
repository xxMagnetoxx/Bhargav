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
#define maxn 10000
using namespace std;
int st[40004];
int ar[10001];

void build(int si , int ss , int se )
{
	if(ss == se)
	{
		st[si]=ar[ss];
		return;
	}
	
	int mid = (ss+se)/2;
	
	build(2*si , ss , mid );
	build(2*si+1 , mid+1 , se);
	
	st[si] = st[2*si] + st[2*si+1];
	
}

int qur(int si , int ss , int se , int qs , int qe)
{
	if(qe<ss || qs>se) return 0;
	
	if( qs<=ss && se<=qe )
	return st[si];
	
	
	int mid = (ss + se)/2;
	
	return (qur(2*si , ss ,mid, qs ,qe) + qur(2*si+1 , mid + 1,se, qs , qe));
	
}

void update(int si , int ss ,int se ,int qi)
{
	if(ss == se)
	{
		st[si] = ar[ss];
		return;
	}
	
	int mid = (ss + se)/2;
	
	if(qi <= mid ) update(2*si , ss , mid , qi);
	else           update(2*si+1 , mid+1 , se , qi);
	
	st[si]  = st[2*si] + st[2*si+1];
}

int main()
{
//FAST
int n;
cin>>n;

for(int i=1;i<=n;i++)
cin>>ar[i];

build(1,1,n);

int qe,a;
cin>>qe;
while(qe--)
{
	cin>>a;
	if(a == 0)
	{
		int m,s;
		cin>>m>>s;
		cout<<qur(1,1,n,m,s);
	}
	else 
	{
		int in,s;
		cin>>in>>s;
		ar[in] = s;
		update(1,1,n,in);
	}
	
}

}






 
