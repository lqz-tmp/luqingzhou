#include <bits/stdc++.h>
using namespace std;

long long pow(long long a,long long b,long long c){
    long long ans=1,tmp=a%c;
    while (b!=0){
        if (b&1)
            ans=((tmp%c)*(ans%c))%c;
            tmp=((tmp%c)*(tmp%c))%c;
            b/=2;
    }
    return ans%c;
}

long long add(long long a,long long b,long long c){
    a%=c;
    b%=c;
    return (a*b)%c;
}

int main(){
    int t;
	long long a,b,c,k;
    cin>>t;
    for (int i=1;i<=t;++i){
        cin>>a>>b>>c>>k;
        if (b-a==c-b){
            long long tmp=add(b-a,k-1,200907)+a;
            cout<<tmp%200907<<endl;
        }else{
            long long tmp=pow(b/a,k-1,200907)*a;
            cout<<tmp%200907<<endl;
        }
    }
    return 0;
}