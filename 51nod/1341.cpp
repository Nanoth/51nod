/*************************************************************************
    > File Name: 1341.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: Mon 23 May 2016 01:29:19 AM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 1000006;
const int mod = 1000000007;

LL qpow(LL a,int b)
{
	LL ret=1;
	for(;b;b>>=1){
		if(b&1)	ret=ret*a%mod;
		a=a*a%mod;
	}
	return ret;
}


int main()
{
	int p,q,r,n;
	LL ans;
	LL q1,p1;
	while(~scanf("%d%d%d%d",&p,&q,&r,&n)){
		q1=qpow(q-1,mod-2);
		p1=qpow(p-1,mod-2);
		LL r3=(LL)3*r%mod*p1%mod;
		if(p==1){
			if(q==p){
				ans=((LL)(n+1)*n/2)%mod*3%mod*r%mod;
			}
			else{
				ans=((qpow(q,n+1)-q)%mod+mod)%mod*q1%mod-n;
				ans%=mod;
				if(ans<0)ans+=mod;
				ans=ans*3%mod*r%mod*q1%mod;
			}
		}
		else{
			if(p==q){
				ans=(n+1)*qpow(q,n)%mod-(qpow(q,n+1)-1+mod)%mod*q1%mod;
				ans%=mod;
				if(ans<0)	ans+=mod;
				ans=ans*r3%mod;
			}
			else{
				ans=(qpow(p,n+1)-qpow(q,n+1)+mod)%mod*qpow(p-q,mod-2)%mod;
				if(q!=1)
					ans-=(qpow(q,n+1)-1)*q1%mod;
				else ans-=n+1;
				ans%=mod;
				if(ans<0)	ans+=mod;
				ans=ans*r3%mod;
			}
		}
		printf("%lld\n",ans);
	}


    return 0;
}
