#include <bits/stdc++.h>
using namespace std;

int f[1000];

int s(int a){
	int ans=0,tmp;
	while(a>0){
		tmp=a%10;
		a/=10;
		ans+=tmp*tmp*tmp;
	}
	return ans;
}

int main(){
	int t=0,ans=0,n=0;
	cin>>n;
	ans=n;
	for (;;){
		t=ans;
		ans=s(ans);
		ans=ans%1000;
		if (t==ans){
			cout<<ans;
			break;
		}
		if (f[ans]==1){
			cout<<"error";
			break;
		}else{
			f[ans]=1;
		}
	}
	return 0;
}