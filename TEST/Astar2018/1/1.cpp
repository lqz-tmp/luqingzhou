#include <bits/stdc++.h>
using namespace std;
 
struct node{
    char st[22];
}an[1100];

int Tmp_ans[2005];

int main(){
    int t,cas=1;
    cin>>t;
    while(cas<=t){
        int n,k,m;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0; i<n; i++)
            scanf(" %s",an[i].st);

        int cnt=0;

        for(int ty=1; ty<(1<<m); ty++){
            memset(Tmp_ans,0,sizeof(Tmp_ans));
            int ans=0;

            for(int i=0; i<n; i++){
                int time=0;
                for(int j=0; j<m; j++){
                    if(ty&(1<<j)){
                        time=time*2+an[i].st[j]-'A';
                    }
                }
                ans+=(i-Tmp_ans[time]);
                Tmp_ans[time]++;
            }
            if(ans>=k){
                cnt++;
            }
        }
        printf("Case #%d: %d\n",cas++,cnt);
    }
    return 0;
}
