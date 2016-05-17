/*************************************************************************
    > File Name: 1294.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: 2016年04月28日 星期四 10时54分01秒
    > url:http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1294
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
#define lson    root<<1,l,m
#define rson    root<<1|1,m+1,r
#define ls      root<<1
#define rs      root<<1|1
const int maxn = 100006;
const int mod = 1000000007;

int a[maxn];
int que[maxn];
int tot;

int bsearch(int k)
{
	if(!tot)	return tot;
	if(que[tot-1]<=k)
	{
		return tot;
	}
	int l=0;
	int r=tot-1;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(que[m]<=k)	l=m+1;
		else r=m-1;
	}
	return l;
}

int main()
{
	int n;
	scan(n);
	tot=0;
	REP(i,1,n+1)	
	{
		scan(a[i]);
		a[i]-=i;
	}
	REP(i,1,n+1)
	{
		if(a[i]<0)	continue;
		int id=bsearch(a[i]);
		if(id==tot)	que[tot++]=a[i];
		else que[id]=a[i];
	}
	cout<<n-tot<<endl;


    return 0;
}
