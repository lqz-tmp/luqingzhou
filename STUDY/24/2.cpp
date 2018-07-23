#include <bits/stdc++.h>
using namespace std;

int n,m,a[105];
long long f[105][105];

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	for (int i=1;i<=n;++i){
		f[i][1]=a[i];
	}
	for (int i=2;i<=m+1;++i){
		for (int j=i-1;j<=n;++j){
			for (int k=j+1;k<=n;++k){
				f[k][i]=max(f[k][i],f[j][i-1]*(a[k]-a[j])); 
			}
		}
	}
	cout<<f[n][m+1];
	return 0;
}