#include <bits/stdc++.h>
using namespace std;

int a[1005][1005],n,f[1005],ans;

void build(){
	for (int i=2;i<=n;++i)
		f[i]=a[1][i];
	f[1]=0;
	for (int i=2;i<=n;++i){
		int ml=100000005,tm=0;
		for (int j=2;j<=n;++j){
			if (f[j]!=0&&f[j]<ml){
				ml=f[j];
				tm=j;
			}
		}
		ans+=ml;
		// cout<<f[tm]<<endl;
		f[tm]=0;
		for (int j=2;j<=n;++j){
			if (f[j]!=0&&a[tm][j]<f[j]){
				f[j]=a[tm][j];
			}
		}
	}
}

int main(){
	cin>>n;
	// for (int i=1;i<=n;++i)
	// 	for (int j=1;j<=n;++j)
	// 		a[i][j]=100000004;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			if (a[i][j]==0) a[i][j]=100000005;
		}
	build();
	cout<<ans<<endl;
	return 0;
}