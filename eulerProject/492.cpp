/*************************************************************************
> File Name: 1003.cpp
> Author: kelvin
> Mail: 444051232@qq.com
> Created Time: Sun 29 May 2016 02:51:02 PM CST
************************************************************************/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
using namespace std;
#define REP(i,a,b)    for(int i=a;i<b;++i)
#define LL        long long
#define mset(a,b)    memset(a,b,sizeof a)
#define scanf		scanf_s
#define scan(n)    scanf("%d",&n)
const int mod = 1000000007;
const int maxn = 1000006;
const int N = 2;

struct M {
	LL a[N + 1][N + 1];
	LL p;
	M(int v = 0) {
		mset(a, 0);
		REP(i, 0, N)	a[i][i] = v;
	}
	M operator *(const M &b) const {
		M ret = 0;
		ret.p = p;
		REP(i, 0, N)	
			REP(j, 0, N)	
				REP(k, 0, N) {
					if (a[i][k] == 0)	continue;
					ret.a[i][j] += a[i][k]%p * b.a[k][j]%p;
					ret.a[i][j] %= p;
				}
		return ret;
	}
	M power(LL n) const
	{
		M ret = 1, a = *this;
		ret.p = p;
		for (; n; n >>= 1) {
			if (n & 1)	ret = ret*a;
			a = a*a;
		}
		return ret;
	}
};


int prime[maxn];
void getp()
{
	REP(i, 2, maxn) {
		if (!prime[i])	prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && i*prime[j] < maxn; ++j) {
			prime[i*prime[j]] = 1;
			if (i%prime[j] == 0)	break;
		}
	}
}

bool notprime[maxn * 10];
int prime2[maxn * 10];
void getP2(int L, int R)
{
	mset(notprime, 0);
	if (L < 2)L = 2;
	for (int i = 1; i <= prime[0] && (LL)prime[i] * prime[i] <= R; ++i) {
		int s = L / prime[i] + (L%prime[i]>0);
		if (s == 1)s = 2;
		for (int j = s; (LL)j*prime[i] <= R; ++j)
			if ((LL)j*prime[i] >= L)
				notprime[j*prime[i] - L] = true;
	}
	prime2[0] = 0;
	for (int i = 0; i <= R - L; ++i)
		if (!notprime[i])prime2[++prime2[0]] = i + L;
}

LL qpow(LL a, LL b, LL m)
{
	LL ret = 1;
	a %= m;
	for (; b; b >>= 1) {
		if (b & 1)	ret = ret*a%m;
		a = a*a%m;
	}
	return ret;
}

LL ans = 0;
LL n = (LL)(mod - 7)*(maxn - 6);

int lrd(int p, int q)
{
	return qpow(p, (q - 1) >> 1, q);
}

LL getans(LL nn,LL p)
{
	M mat;
	mat.p = p;
	mat.a[0][0] = 11; mat.a[0][1] = -1; mat.a[1][0] = 1; mat.a[1][1] = 0;
	if (lrd(13, p) == 1) mat = mat.power(qpow(2, nn - 1, p - 1)-1);
	else mat = mat.power(qpow(2, nn - 1, p + 1)-1);
	LL b=(((LL)mat.a[0][0]*11%p+(LL)mat.a[0][1]*2%p)%p+p)%p;
	return (b + p - 5) % p*qpow(6, p - 2, p)%p;
}

int main()
{ 
	LL a = 1;
	REP(i, 1, 10)
	{
		cout << i << ' ' << a<<endl;
		a = 6ll * a*a%mod + 10 * a%mod + 3;
		a %= mod;
	}
	getp();
	int e9 = mod - 7;
	getP2(e9, e9+e9/100);
	REP(i, 1, 10)	cout << i << ' ' << getans(i, mod) << endl;
	cout << 100 << ' ' << getans(100, mod) << endl;
	//REP(i, 1, 30)	cout << i << ' ' << prime2[i] << endl;
	REP(i, 1, prime2[0] + 1) {
		LL p = prime2[i];
		LL tmp = getans(n,p);
		//if (tmp < 0)	cout << p << endl;
		ans += tmp;
	}
	cout << ans << endl;
	return 0;
}
