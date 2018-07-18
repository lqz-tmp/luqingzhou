#include <bits/stdc++.h>
using namespace std;

int f[20005];

int main() {
	int v,n,a[35];
	cin>>v>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	for (int i=1;i<=n;++i){
		for (int j=v;j>=a[i];--j){
			f[j]=max(f[j],f[j-a[i]]+a[i]);
		}
	}
	int ans=f[v];
	ans=v-ans;
	cout<<ans;
    return 0;
}