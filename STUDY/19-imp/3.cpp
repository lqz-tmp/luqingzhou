#include <bits/stdc++.h>
using namespace std;
 
int b[10000005],c[10000005];
 
bool check(int x){
    for (int i=2;i<=int(sqrt(x));++i){
        if (x%i==0) return false;
    }
    return true;
}
 
int main(){
    int n,l,a[105],j;
    cin>>n>>l;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    int tmp;
    for (int i=1;i<=n-l+1;++i){
        tmp=0;
        if (a[i]==0) continue;
        for (int k=1;k<=l;++k){
            tmp=tmp*10+a[i+k-1];
        }
        if (check(tmp)) c[tmp]=1;
    }
    int t=0;
    for (int i=1;i<=9999999;++i){
        if (c[i]==1){
            if (t==0) cout<<i;
            else cout<<','<<i;
            t++;
        }
    }
    return 0;
}