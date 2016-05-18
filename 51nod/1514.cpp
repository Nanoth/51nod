/*************************************************************************
    > File Name: 1514.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: 2016年05月16日 星期一 17时15分06秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 100005;
const int mod = 998244353;
const int G = 3;
int fac[maxn<<3];

int qpow(int a,int b,int mod)
{
	int ret=1;
	for(;b;b>>=1){
		if(b&1)	ret=(LL)ret*a%mod;
		a=(LL)a*a%mod;
	}
	return ret;
}

struct _NTT {
	int wn[25], P;

	void init(int _P) {
		P = _P;
		for(int i = 1; i <= 21; ++i) {
			int t = 1 << i;
			wn[i] = qpow(G, (P - 1) / t, P);
		}
	}
	void change(int *y, int len) {
		for(int i = 1, j = len / 2; i < len - 1; ++i) {
			if(i < j) swap(y[i], y[j]);
			int k = len / 2;
			while(j >= k) {
				j -= k;
				k /= 2;
			}
			j += k;
		}
	}
	void NTT(int *y, int len, int on) {
		change(y, len);
		int id = 0;
		for(int h = 2; h <= len; h <<= 1) {
			++id;
			for(int j = 0; j < len; j += h) {
				int w = 1;
				for(int k = j; k < j + h / 2; ++k) {
					int u = y[k];
					int t = 1LL * y[k+h/2] * w % P;
					y[k] = u + t;
					if(y[k] >= P) y[k] -= P;
					y[k+h/2] = u - t + P;
					if(y[k+h/2] >= P) y[k+h/2] -= P;
					w = 1LL * w * wn[id] % P;
				}
			}
		}
		if(on == -1) {
			for(int i = 1; i < len / 2; ++i) swap(y[i], y[len-i]);
			int inv = qpow(len, P - 2, P);
			for(int i = 0; i < len; ++i) 
				y[i] = 1LL * y[i] * inv % P;
		}
	}
	void mul(int A[], int B[], int len) {
		NTT(A, len, 1);
		NTT(B, len, 1);
		for(int i = 0; i < len; ++i) A[i] = 1LL * A[i] * B[i] % P;
		NTT(A, len, -1);
		NTT(B,len,-1);
	}
}ntt;

void init()
{
	fac[0]=1;
	REP(i,1,maxn)	fac[i]=(LL)i*fac[i-1]%mod;
}


int tmp[maxn<<3];
void inv(int A[],int B[],int len)
{
	if(len==1){
		B[0]=qpow(A[0],mod-2,mod);
		return ;
	}
	inv(A,B,(len+1)>>1);
	int k=1;
	while(k<=(len<<1)+3)	k<<=1;
	REP(i,0,len)	tmp[i]=A[i];
	REP(i,len,k)	tmp[i]=0;
	ntt.NTT(tmp,k,1);
	ntt.NTT(B,k,1);
	REP(i,0,k)	{
		tmp[i]=2-(LL)tmp[i]*B[i]%mod+mod;
		tmp[i]%=mod;
		if(tmp[i]<0)	tmp[i]+=mod;
	}
	REP(i,0,k)	B[i]=(LL)B[i]*tmp[i]%mod;
	ntt.NTT(B,k,-1);
	REP(i,len,k)	B[i]=0;
}
int B[maxn<<3];
int main()
{
	ntt.init(mod);
	init();
	int len=1;
	while(len<=(maxn)) len<<=1;
	inv(fac,B,len);
	REP(i,0,maxn)	B[i]=mod-B[i];
	B[0]=0;
	int t,n;
	~scan(t);
	while(t--){
		scan(n);
		printf("%d\n",B[n]);
	}


    return 0;
}
