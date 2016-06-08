/*************************************************************************
    > File Name: 1354.cpp
    > Author: kelvin
    > Mail: 444051232@qq.com 
    > Created Time: 2016年06月07日 星期二 21时57分27秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)	for(int i=a;i<b;++i)
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)
#define scan(n)	scanf("%d",&n)
const int maxn = 1003;
const int mod = 1000000007;

int a[maxn];
int fac[33],yue[maxn],cntyue;
int num[33],cnt;
map<int,int>mp;
void div(int k)
{
	cnt=0;
	REP(i,2,k){
		if(i*i>k)	break;
		if(k%i)	continue;
		fac[cnt]=i;
		num[cnt]=0;
		while(k%i==0)	{
			num[cnt]++;
			k/=i;
		}
		cnt++;
	}
	if(k!=1){
		fac[cnt]=k;
		num[cnt++]=1;
	}
}
void dfs(int cur,int dep)
{
	if(dep==cnt){
		yue[cntyue++]=cur;
		return ;
	}
	int tmp=1;
	REP(i,0,num[dep]+1){
		dfs(cur*tmp,dep+1);
		tmp*=fac[dep];
	}
}

void getyue()
{
	cntyue=0;
	dfs(1,0);
	sort(yue,yue+cntyue);
}
LL dp[maxn][maxn];
int main()
{
	//freopen("data1354","r",stdin);
	int t,n,k;
	scan(t);
	while(t--){
		scanf("%d%d",&n,&k);
		int c=0;
		while(n--)
		{
			scan(a[c]);
			if(k%a[c]==0)	c++;
		}
		div(k);
		getyue();
		mset(dp,0);
		mp.clear();
		REP(i,0,cntyue)	mp[yue[i]]=i;
		dp[0][0]=1;
		REP(i,0,c){
			for(int j=cntyue-1;j>=0;--j){
				dp[i+1][j]+=dp[i][j];
				dp[i+1][j]%=mod;
				if(yue[j]*a[i]<=k && k%(a[i]*yue[j])==0){
					dp[i+1][mp[yue[j]*a[i]]]+=dp[i][j];
					dp[i+1][mp[yue[j]*a[i]]]%=mod;
					//if(dp[i][j])	cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<dp[i+1][j]<<' '<<' '<<mp[yue[j]*a[i]]<<' '<<dp[i+1][mp[yue[j]*a[i]]]<<endl;
				}
			}
		}
		printf("%lld\n",dp[c][cntyue-1]);
	}


    return 0;
}
