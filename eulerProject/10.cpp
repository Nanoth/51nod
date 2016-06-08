/*************************************************************************
    > File Name: 10.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: Wed 08 Jun 2016 03:17:06 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 1000006;
const int mod = 1000000007;

bool isp[maxn];
int prime[maxn];
map<int,map<int,LL > > s;
LL sum[maxn];
void init()
{
	REP(i,2,maxn){
		if(!isp[i]){
			prime[++prime[0]]=i;
		}
		for(int j=1;j<=prime[0] && prime[j]*i<maxn;++j){
			isp[i*prime[j]]=1;
			if(i%prime[j]==0)	break;
		}
	}
	REP(i,1,prime[0]+1)	sum[i]=sum[i-1]+prime[i];
}

LL solve(LL v,LL p)
{
	if(p<2)	return v*(v+1)/2; 
	if(isp[p]!=0)	return solve(v,p-1);
	if((LL)p*p>v)	return solve(v,p-1);
	if(s.count(v)>0 && s[v].count(p)>0)	return s[v][p];
	LL ret=solve(v,p-1)-(LL)p*(solve(v/p,p-1)-solve(p-1,p-1));
	s[(int)v][p]=ret;
}
int main()
{
	init();
	int n;
	scan(n);
	cout<<solve(n,(int)(sqrt(n+0.5))+1)-1<<endl;
//	LL ret=0;
//	REP(i,1,prime[0]+1)	{
//		if(prime[i]>n)	break;
//		ret+=prime[i];
//	}
//	cout<<ret<<endl;
	

    return 0;
}
