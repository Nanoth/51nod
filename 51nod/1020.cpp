#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)      for(int i=a;i<b;++i)
const int maxn=1003;
const int maxk=20004;
const int mod=1e9+7;

int f[maxn][maxk+10];

int main()
{
    int t;
    scanf("%d",&t);
    int n,k;
    f[1][0]=1;
    REP(i,2,maxn){
        f[i][0]=1;
        for(int j=1;j<=min(maxk,(i-1)*i/2);++j){
            f[i][j]=f[i-1][j];
            if(j>0) f[i][j]+=f[i][j-1];
            if(j>=i)    f[i][j]-=f[i-1][j-i];
            f[i][j]%=mod;
            if(f[i][j]<0)   f[i][j]+=mod;
        }
    }
    while(t--){
        scanf("%d%d",&n,&k);
        printf("%d\n",f[n][k]);
    }
}
