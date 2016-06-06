/*************************************************************************
    > File Name: 1189.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: 2016年06月06日 星期一 20时09分29秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 1000006;
const int mod = 1000000007;

int prime[maxn];
void getP()
{
	REP(i,2,maxn){
		if(!prime[i])	prime[++prime[0]]=i;
		for(int j=1;j<=prime[0] && prime[j]*i<maxn;++j){
			prime[i*prime[j]]=1;
			if(i%prime[j]==0)	break;
		}
	}
}

inline int getp(int n,int p)
{
	int ret=0;
	while(n){
		ret+=n/p;
		n/=p;
	}
	return ret;
}

int getans(int n)
{
	LL ret=1;
	REP(i,1,prime[0]+1){
		int p=prime[i];
		if(p>n)	break;
		int k=getp(n,p);
		ret=ret*(2*k+1)%mod;
	}
	ret++;
	ret=ret*((mod+1)>>1)%mod;
	return ret;
}

int main()
{
	getP();
	int n;
	cin>>n;
	cout<<getans(n)<<endl;


    return 0;
}
