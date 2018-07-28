#include <bits/stdc++.h>
using namespace std;

int p,tmp[1005],ans[1005],a[1005];

void ch(){
	memset(tmp,0,sizeof(tmp));
	for (int i=1;i<=500;++i){
		for (int j=1;j<=500;++j){
			tmp[i+j-1]+=ans[i]*a[j];
		}
	}
	for (int i=1;i<=500;++i){
		tmp[i+1]+=tmp[i]/10;
		tmp[i]%=10;
	}
	memcpy(ans,tmp,sizeof(tmp));
}

void th(){
	memset(tmp,0,sizeof(tmp));
	for (int i=1;i<=500;++i){
		for (int j=1;j<=500;++j){
			tmp[i+j-1]+=a[i]*a[j];
		}
	}
	for (int i=1;i<=500;++i){
		tmp[i+1]+=tmp[i]/10;
		tmp[i]%=10;
	}
	memcpy(a,tmp,sizeof(tmp));
}

int main(){
	cin>>p;
	int t1=int(log10(2)*p+1);
	cout<<t1;
	a[1]=2;
	ans[1]=1;
	while (p){
		if (p&1) ch();
		p>>=1;
		th();
	}
	ans[1]--;
	for (int i=500;i>=1;--i){
		if (i%50==0) cout<<endl;
		cout<<ans[i];
	}
	return 0;
}