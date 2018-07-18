#include <bits/stdc++.h>
using namespace std;

int a[300005];

int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int tmp=0,sum=0;
    for (int i=1;i<=n;++i){
        tmp=max(tmp,a[i]+n-i+1);
    }
    for (int i=n;i>=1;--i){
        if (a[i]+n>=tmp) sum++;
        else break;
    }
    cout<<sum<<endl;
    return 0;
}