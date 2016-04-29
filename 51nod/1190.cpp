/*************************************************************************
    > File Name: 1190.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: 2016年04月28日 星期四 17时39分16秒
    反演
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 1000006;
const int mod = 1000000007;

int fac[33],num[33],cnt;
int prime[maxn];
void getP()
{
	REP(i,2,maxn)
	{
		if(!prime[i])	prime[++prime[0]]=i;
		for(int j=1;j<=prime[0] && prime[j]<=maxn/i;++j)
		{
			prime[i*prime[j]]=1;
			if(i%prime[j]==0)	break;
		}
	}
}

void div(int b)
{
	cnt=0;							
	int x=b;
	REP(i,1,prime[0]+1)
	{
		LL p=prime[i];
		if(p*p>x)	break;
		if(x%p)	continue;
		fac[cnt]=p;
		num[cnt]=0;
		while(x%p==0)
		{
			x/=p;
			num[cnt]++;
		}
		cnt++;
	}
	if(x!=1)
	{
		fac[cnt]=x;
		num[cnt++]=1;
	}
}
LL a,b;
inline void init()
{
	div(b);
}
inline LL up(int x,int y)
{
	return (x-1)/y+1;
}
LL getans(int d,LL mu)
{
	LL ret=1;
	LL x=up(a,d);
	LL y=b/d-x+1;
	x+=b/d;
	ret=x*y/2%mod;
	ret=ret*mu%mod;
	if(ret<0)	ret+=mod;
	return	ret; 
}

LL ans;
void dfs(int cur,int dep,LL mu)
{
	if(dep==cnt)
	{
		ans+=getans(cur,mu);
		ans%=mod;
		return ;
	}
	
	REP(i,0,num[dep]+1)
	{
		dfs(cur,dep+1,mu);
		cur*=fac[dep];
		if(!i)	mu=mu*(1-fac[dep])%mod;
	}
}


int main()
{
	//freopen("1190.in","r",stdin);
	//freopen("1190.out","w",stdout);
	getP();
	int t;
	scan(t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		init();
		ans=0;
		dfs(1,0,1);
		ans=ans*b%mod;
		if(ans<0)	ans+=mod;
		printf("%lld\n",ans);
		
	}

    return 0;
}
