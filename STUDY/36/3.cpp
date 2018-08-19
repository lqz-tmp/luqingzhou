#include <bits/stdc++.h>
using namespace std;

int a[100005],n;
long long sum,ans;

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	sum=a[1];
	for (int i=2;i<=n;++i){
		ans+=(long long)(i-1)*(long long)a[i]-sum;
		sum+=a[i];
	}
	cout<<ans;
	return 0;
}