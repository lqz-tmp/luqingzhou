#include <bits/stdc++.h>
using namespace std;

int a[2000],n,t,m,tmp,ans;
int pow(int m){
	int ans=1;
	for (int i=1;i<=m;i++){
		ans*=2;
	}
	return ans;
}
int q(int a,int b){
	if ((a==-1)&(b==-1)) return -1;
	return 0;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d",&tmp);
		a[tmp]=-1;
	}
	t=pow(n);
	for (int i=1;i<=n+1;i++){
		for (int j=1;j<=t/2;j++){
			if (a[j*2]!=a[j*2-1]) ans++;
		}
		for (int j=1;j<=t/2;j++){
			a[j]=q(a[2*j],a[2*j-1]);
		}
		t/=2;

	}
	cout<<ans<<endl;
	return 0;
}