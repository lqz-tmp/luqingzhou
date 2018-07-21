#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    char c[100005];
    scanf("%s",c+1);
    int low=0,up=0,tl=0,tu=0,ans=999999999;
    int len=strlen(c+1);
    for (int i=1;i<=len;++i){
        if (c[i]>='a'&&c[i]<='z') low++;
        else if (c[i]>='A'&&c[i]<='Z') up++;
    }
    for (int i=0;i<=len;++i){
        if (c[i]>='a'&&c[i]<='z') tl++;
        else if (c[i]>='A'&&c[i]<='Z') tu++;
        ans=min(ans,tl+up-tu);
    }
    cout<<ans;
    return 0;
}