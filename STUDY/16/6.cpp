#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return(a>b);
}

int main(){
    int n,a[100004]{0};
    long long sum=0;
    cin>>n;
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i+=3){
        sum+=a[i]+a[i+1];
    }
    cout<<sum;
    return 0;
}