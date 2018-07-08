#include <bits/stdc++.h>
using namespace std;
long long ans;
int main(){
	int n;
	scanf("%d",&n);
	int a[n+1];
	for (int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int i;
	for (i=n;i>3;i-=2){
		if ((2*a[2]+a[1]+a[i])>(2*a[1]+a[i]+a[i-1])) ans=ans+2*a[1]+a[i]+a[i-1];
		else ans=ans+2*a[2]+a[1]+a[i];
	}
	if (i==2) ans+=a[2];
	if (i==3) ans=ans+a[1] + a[2] + a[3];  
	if (i==1) ans+=a[1];
	cout<<ans<<endl;
	return 0;
}