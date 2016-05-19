#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int cnt[26];
int num;
char s[maxn];
int main()
{
    scanf("%s",s);
    int j=0;
    int len=strlen(s);
    int ans=maxn;
    for(int i=0;s[i];++i){
        if(cnt[s[i]-'A']==0){
            num++;
        }
        cnt[s[i]-'A']++;
        while(j<i){
            if(cnt[s[j]-'A']>1) {
                cnt[s[j]-'A']--;j++;
            }
            else break;
        }
        if(num==26){
            ans=min(ans,i-j+1);
        }
    }
    if(ans==maxn)   puts("No Solution");
    else cout<<ans<<endl;
}
