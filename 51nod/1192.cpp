/*************************************************************************
    > File Name: 1192.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: 2016年05月18日 星期三 10时49分45秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 5000006;
const int mod = 1000000007;

int prime[maxn];
LL f[maxn];
int mu[maxn];
void getP()
{
	mu[1]=1;
	REP(i,2,maxn){
		if(!prime[i]){
			prime[++prime[0]]=i;
			mu[i]=-1;	
			f[i]=1;
		}
		for(int j=1;j<=prime[0] && (LL)prime[j]*i<maxn;++j){
			prime[i*prime[j]]=1;
			if(i%prime[j])
			{
				f[i*prime[j]]=mu[i]-f[i];
				mu[i*prime[j]]=-mu[i];
			}
			else{
				f[i*prime[j]]=mu[i];
				 break;
			}
		}
	}
	REP(i,2,maxn)	f[i]+=f[i-1];
}


LL getans(int n,int m)
{
	LL ret=0;
	for(int d=1,j;d<=n;d=j+1){
		j=min(m/(m/d),n/(n/d));
		ret+=(LL)(n/d)*(m/d)*(f[j]-f[d-1]);
	}
	return ret;
}

int main()
{
	getP();
	int t;
	scan(t);
	int m,n;
	while(t--){
		scanf("%d%d",&m,&n);
		if(n>m)	swap(n,m);
		LL ans=getans(n,m);
		cout<<ans<<endl;
	}


    return 0;
}
