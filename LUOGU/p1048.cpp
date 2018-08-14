#include <bits/stdc++.h>
using namespace std;
int f[30005];
int main(){
	int t,n,a[1005],p[1005];
	cin>>t>>n;
	for (int i=1;i<=n;++i)
		scanf("%d %d",&a[i],&p[i]);
	for (int i=1;i<=n;++i){
		for (int j=t;j>=1;--j){
			if (j>=a[i]) {
				f[j]=max(f[j],f[j-a[i]]+a[i]*p[i]);
			}
			else break;
		}
	}
	cout<<f[t];
	return 0;
}