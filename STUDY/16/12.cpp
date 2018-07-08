#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,tmp,last=0,ans=0;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        scanf("%d",&tmp);
        if (tmp>=last&&tmp>=m) {
            ans++;
            last=tmp;
        }else if (tmp*2>=last&&tmp*2>=m){
            ans++;
            last=tmp*2;
        }else{
            last=0;
        }
    }
    cout<<ans;
    return 0;
}