#include<bits/stdc++.h>
using namespace std;

int a[10005];

int main(){
    int n,t,x;
    cin>>n>>t>>x;
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    return 0;
}