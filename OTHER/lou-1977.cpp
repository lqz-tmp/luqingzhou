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

int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<pow(a,b,c)<<endl;
}