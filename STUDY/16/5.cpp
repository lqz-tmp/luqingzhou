#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,n,a[105],ans=0;
    cin>>k>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=k;++i){
        ans+=a[n-i+1]-a[i];
    }
    cout<<ans;
    return 0;
}