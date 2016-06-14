/*************************************************************************
    > File Name: 1711.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: 2016年06月14日 星期二 13时52分36秒
 ************************************************************************/

#include<stdio.h>
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 500005;

int mu[maxn],a[maxn];
bool flag[maxn];
int cnt[maxn];
int prime[maxn];
int minfac[maxn];

inline LL read(){
    LL x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';){if(ch=='-')f=-1;ch=getchar();}
    for(;ch>='0'&&ch<='9';){x=x*10ll+ch-'0';ch=getchar();}
    return x*f;
}
void init()
{
	mu[1]=1;
	minfac[1]=1;
	REP(i,2,maxn){
		if(!prime[i]){
			prime[++prime[0]]=i;
			mu[i]=-1;
			minfac[i]=i;
		}
		for(int j=1;j<=prime[0] && i*prime[j]<maxn;++j){
			prime[i*prime[j]]=1;
			minfac[i*prime[j]]=prime[j];
			if(i%prime[j])	mu[i*prime[j]]=-mu[i];
			else break;
		}
	}
}
int fac[10];
int num;
int dfsres;
int op=1;
void dfs(int cur,int dep,int b)
{
	if(dep==num){
		if(op==-1)	cnt[cur]+=op;
		dfsres+=cnt[cur]*b;
		if(op==1)	cnt[cur]+=op;
		return ;
	}
	dfs(cur,dep+1,b);
	dfs(fac[dep]*cur,dep+1,-b);
}
int solve(int A,bool f)
{
	op=1;
	if(f)	op=-1;	
	int x=A;
	num=0;
	while(x!=1){
		int p=minfac[x];
		fac[num++]=p;
		while(x%p==0)x/=p;		
	}
	dfsres=0;
	dfs(1,0,1);

	return dfsres*op;

}

int main()
{
	init();
	int n,q,x;
	n=read();q=read();
	REP(i,1,n+1)	a[i]=read();	
	LL ans=0;
	while(q--){
		scan(x);
		ans+=solve(a[x],flag[x]);
		flag[x]^=1;
		printf("%lld\n",ans);
	}


    return 0;
}
