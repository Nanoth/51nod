#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b)		for(int i=a;i<b;++i)
#define mset(a,b)		memset(a,b,sizeof a)
#define LL				long long
const int maxn = 100005;
const int mod = 1000000007;
int prime[maxn];
int num[maxn];
int cnt;
void getP()
{
	mset(prime, 0);
	REP(i, 2, maxn)
	{
		if (!prime[i])	prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && prime[j] * i < maxn; ++j)
		{
			prime[i*prime[j]] = 1;
			if (i%prime[j] == 0)	break;
		}
	}
}
void init(int n)
{
	mset(num, 0);
	int p;
	int tmp;
	for (cnt = 1; cnt <= prime[0];++cnt)
	{
		p = prime[cnt];
		if (p > n)	break;
		tmp = n;
		while (tmp) {
			num[cnt] += tmp / p;
			tmp /= p;
		}
	}
	num[1]--;
}

LL qmod(LL a, int b)
{
	LL ret = 1;
	a %= mod;
	for (; b; b >>= 1) {
		if (b & 1)	ret = ret*a%mod;
		a = a*a%mod;
	}
	return ret;
}

int solve()
{
	LL ret=1;
	LL p, k;
	REP(i, 1, cnt) {
		p = prime[i];
		k = num[i];
		LL tmp = (((k + 1)*qmod(p, k) % mod - k*qmod(p, k - 1) % mod) % mod + mod) % mod;
		(ret *= tmp) %= mod;
	}
	return ret;
}
int main()
{
	getP();
	int t, cas = 1;
	scanf("%d", &t);
	int ans;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (n < 4)	ans = 4 * n - 7;
		else {
			init(n);
			ans = solve();
		}
		printf("Case #%d: %d\n", cas++, ans);
	}
	return 0;
}
