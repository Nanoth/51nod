#include<bits/stdc++.h>

#define REP(i,a,b)		for(int i=a;i<b;++i)
#define mset(a,b)		memset(a,b,sizeof a)
#define LL				long long
const int maxn = 1000006;
const int mod = 1000000007;
LL f[maxn], sumf[maxn], h[maxn], mu[maxn];
int prime[maxn];

void getP()
{
	mu[1] = 1;
	h[1] = 1;
	REP(i, 2, maxn)
	{
		if (!prime[i])
		{
			mu[i] = -1;
			prime[++prime[0]] = i;
			h[i] = i + 1;
		}
		for (int j = 1; j <= prime[0] && (LL)prime[j]*i < maxn ; ++j)
		{
			prime[i*prime[j]] = 1;
			if (i%prime[j]) {
				mu[i*prime[j]] = -mu[i];
				h[i*prime[j]] = h[i] * (1 + prime[j]) % mod;
			}
			else
			{
				int tmp = i;
				LL p = prime[j];
				LL s = p + 1;
				while (tmp%prime[j] == 0) {
					tmp /= prime[j];
					(p *= prime[j])%=mod;
					s += p;
					s%=mod;
				}
				h[i*prime[j]] = h[tmp] * s%mod;
				break;
			}
		}
	}
}

void init()
{
	getP();
	REP(i, 1, maxn) {
		(h[i] += h[i - 1]) %= mod;
		mu[i] = i*mu[i] % mod;
		h[i-1]=h[i-1]*h[i-1]%mod;
	}
	//REP(i, 1, maxn)	h[i] = h[i] * h[i] % mod;
	for (int i = maxn - 1; i > 0; --i)	h[i] = (h[i] - h[i - 1]) % mod;
	REP(i, 1, maxn)
	{
		for (int j = 1; j*i < maxn; ++j)
		{
			f[i*j] += mu[i] * h[j] % mod;
			if (f[i*j] > mod)	f[i*j] -= mod;
		}
	}
	REP(i, 1, maxn)	(f[i] += f[i - 1]) %= mod;
	REP(i, 1, maxn)	sumf[i] = (sumf[i - 1] + f[i]) % mod;
	REP(i, 1, maxn)	f[i] = ((i*f[i] % mod - sumf[i - 1]) % mod + mod) % mod;
}

char str[10];
int getint()
{
	scanf("%s", str);
	int ret = 0;
	for (int i = 0; str[i]; ++i)
	{
		ret = ret * 10 + str[i] - '0';
	}
	return ret;
}
int main()
{
	init();
	int t, cas = 1;
	scanf("%d", &t);
	int n;
	while (t--)
	{
		n = getint();
		printf("Case #%d: %lld\n", cas++, f[n]);
	}
	return 0;
}
