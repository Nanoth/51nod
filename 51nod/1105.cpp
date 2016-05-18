/*************************************************************************
    > File Name: 1105.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: 2016年05月18日 星期三 10时14分07秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 50004;
const int mod = 1000000007;

int a[maxn],b[maxn];
int n,k;

LL lar(LL m)
{
	LL ret=(LL)n*n;	
	int j=n-1;
	REP(i,0,n){
		while(j>=0 && (LL)a[i]*b[j]>=m)	j--;
		if(j<0)	break;
		ret-=j+1;
	}
	return ret;
}

LL getans(int k)
{
	LL l=(LL)a[0]*b[0];
	LL r=(LL)a[n-1]*b[n-1];
	while(l<=r){
		LL m=(l+r)>>1;
		if(lar(m)>=k)	l=m+1;
		else r=m-1;
	}
	return l-1;
}

int main()
{
	scan(n);
	scan(k);
	REP(i,0,n)	scanf("%d%d",a+i,b+i);
	sort(a,a+n);
	sort(b,b+n);
	LL ans = getans(k);
	cout<<ans<<endl;

    return 0;
}
