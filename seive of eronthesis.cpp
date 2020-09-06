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
int pri[10000000];
void prme(int n)
{
	bool prime[n+1];
	memset(prime , true , sizeof prime);
	
	prime[1] = false;
	
	for(int p=2;p*p<=n;p++)
	{
		if(prime[p] == true)
		{
			for(int i = p*p;i<=n;i++)
			{
				prime[i] = false;
			}
		}
	}

for(int i=2;i<=n;i++)
{
	if(prime[i])
	pri[i]=pri[i-1]+1;
	
	else
	pri[i]=pri[i-1];
}
}


int main()
{
FAST
int T;
cin>>T;
ll n,cnt=0;
prime(1000000);
while(T--)
{
cin>>n;
cout<<pri[n]-cnt<<endl;
cnt+=pri[n];
}
}







