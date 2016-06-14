/*************************************************************************
    > File Name: 1643.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: 2016年06月13日 星期一 20时11分02秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define LL		long long
const int maxn = 10000007;
const int mod = 1000000007;

inline LL read(){
    LL x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';){if(ch=='-')f=-1;ch=getchar();}
    for(;ch>='0'&&ch<='9';){x=x*10ll+ch-'0';ch=getchar();}
    return x*f;
}

int pflag[maxn];
int p2[maxn];
int minfac[maxn];

int qpow(LL a,LL b)
{
	a%=mod;
	b%=mod-1;
	LL ret=1;
	for(;b;b>>=1){
		if(b&1)	ret=ret*a%mod;
		a=a*a%mod;
	}
	return ret;
}
LL ans;
int maxx=0;
inline void add(int &a,int &b,const int &m)
{
	a+=b;
	if(a>m)	a-=m;
}
int main()
{
	ans=1;
	LL x,a,b,c;
	LL m;
	m=read();x=read();a=read();b=read();c=read();
	//scanf("%lld%lld%lld%lld%lld",&m,&x,&a,&b,&c);
	int i;
	for(i=1;i<=m;++i){
		if(pflag[x])	break;
		pflag[x]=i;
		p2[x]=1;
		ans=ans*x%mod;
		if(x>maxx)maxx=x;
		minfac[i]=x;
		x=(a*x+b)%c+1;
	}
	int xun=i-pflag[x];
	if(i<=m){
		m-=i-1;
		LL d=m/xun;
		int d1=d%mod;
		int md=m%xun;
		LL tmp=1;
		int beg=pflag[x];
		for(int j=0;j<xun;++j){
			if(j<md)	p2[x]++,ans=ans*x%mod;
			tmp=tmp*x%mod;
			add(p2[x],d1,mod);
			x=minfac[++beg];
		}
		ans=ans*qpow(tmp,d)%mod;
	}
    pflag[0]=0;
	
	memset(minfac,0,i*sizeof(int));
	for(int i=2;i<=maxx;++i){
		if(!minfac[i]){
			pflag[++pflag[0]]=i;
		}
		for(int j=1;j<=pflag[0] && pflag[j]*i<=maxx;++j){
			minfac[i*pflag[j]]=pflag[j];
			if(i%pflag[j]==0)	break;
		}
	}
	for(int i=maxx;i>1;--i){
		if(!p2[i])	continue;
		if(minfac[i]){
			add(p2[minfac[i]],p2[i],mod);
			add(p2[i/minfac[i]],p2[i],mod);
			
		}
		else ans=ans*((1+p2[i]))%mod;
	}
	printf("%lld\n",ans);

    return 0;
}
