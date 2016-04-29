/*************************************************************************
    > File Name: 1515_2.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: Mon 18 Apr 2016 09:52:48 PM CST
    有待改进
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 2000006;
const int mod = 1000000007;

map<int,int> hash;
int cnt;

int fa[maxn];
set<int> setno[maxn];

int gets(int x)
{
	if(!hash.count(x))	hash[x]=++cnt;
	return hash[x];
}

int getfa(int x)
{
	if(fa[x]==x)	return x;
	return fa[x]=getfa(fa[x]);
}

void ko(int x,int y)
{
	setno[x].insert(y);
	setno[y].insert(x);
}

set<int>::iterator it;
bool check(int x,int y)
{
    if(setno[x].find(y)!=setno[x].end())    return true;
    x=getfa(x);
    y=getfa(y);
	int tmpfa;
	for(it=setno[x].begin();it!=setno[x].end();++it)
	{
		tmpfa=getfa(*it);
		if(setno[tmpfa].count(x))   setno[x].erase(it);
		//if(tmpfa!=*it && setno[x].count(tmpfa)>0)  setno[x].erase(it);
		//if(setno[x].find(tmpfa)==setno[x].end())    setno[x].insert(tmpfa);
		//setno[x].erase(it);
		//setno[x].insert(tmpfa);
		if(y==tmpfa)	return true;
	}
	return false;
}

void join(int x,int y)
{
	set<int>::iterator it;
	int tmpfa;
	for(it=setno[x].begin();it!=setno[x].end();++it)
	{
		tmpfa=getfa(*it);
		setno[tmpfa].insert(y);
		//setno[y].insert(tmpfa);
	}
	setno[x].clear();
	fa[x]=getfa(y);
}

void un(int x,int y)
{
	if(setno[x].size()<setno[y].size())	join(x,y);
	else join(y,x);
}

void solve(int x,int y,int p)
{
	if(p)
	{
		if(!setno[x].empty() && check(x,y) || !setno[y].empty()&&check(y,x))	puts("NO");
		else
		{
			puts("YES");
			un(x,y);
		}
	}
	else
	{
		if(x==y)	puts("NO");
		else
		{
			puts("YES");
			if(check(x,y))  return ;
			ko(x,y);
		}
	}
}

void init(int n=maxn)
{
	cnt=0;
	hash.clear();
	REP(i,0,n)	fa[i]=i;
}
int main()
{
//	freopen("in1515","r",stdin);
//	freopen("out1515","w",stdout);
	int n;
	int x,y,p;
	scan(n);
	init();
	while(n--)
	{
		scanf("%d%d%d",&x,&y,&p);
		x=gets(x);
		x=getfa(x);
		y=gets(y);
		y=getfa(y);
		solve(x,y,p);

	}


    return 0;
}
