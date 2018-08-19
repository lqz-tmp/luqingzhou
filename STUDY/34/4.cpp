#include <bits/stdc++.h>
using namespace std;

int cc(int k,int n){
	long long t1=1,t2=1,ans=1;
	for (int i=k-n+1;i<=k;++i){
		t1=t1*i%10007;
	}
	for (int i=1;i<=n;++i){
		t2=t2*i%10007;
	}
	for (int i=0;i<=10007;++i){
		if (i*t2%10007==t1) return i;
	}
	return -1;
}

long long powe(long long a,long long b){
	int c=10007;
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
	int a,b,k,n,m;
	cin>>a>>b>>k>>n>>m;
	long long ans=powe(a,n);
	ans=ans*powe(b,m)%10007;
	ans=ans*cc(k,n)%10007;
	cout<<ans;
	return 0;
}