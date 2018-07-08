#include<bits/stdc++.h>
using namespace std;
 
int a[10005],af[10005];  //af：负数时刻  a：非负数时刻
 
int main(){
    int n,t,x,ti[10005],tmp,ans=0,j;
    cin>>n>>t>>x;
    for (int i=1;i<=n;++i){
        scanf("%d",&ti[i]);
    }
    if (t<x){
        cout<<-1<<endl;
        return 0;
    }
    for (int i=1;i<=n;++i){
        tmp=0;
        for (int j=ti[i]-t;j<=ti[i]-1;++j){
            if (j>=0) {
                if(a[j]==1){
                    tmp++;
                }
            }else{
                if(af[-j]==1){
                    tmp++;
                }
            }
        }
        j=ti[i]-1;
        while(tmp<x){
            if (j>=0) {
                if(a[j]!=1){
                    a[j]=1;
                    ans++;
                    tmp++;
                }
            }else{
                if(af[-j]!=1){
                    af[-j]=1;
                    ans++;
                    tmp++;
                }
            }
            j--;
        }
    }
    cout<<ans<<endl;
    return 0;
}