#include <bits/stdc++.h>
using namespace std;

int a[205][205];

int main(){
	int n,m;
	cin>>n;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			for (int k=1;k<=n;++k){
				a[j][k]=min(a[j][k],a[i][j]+a[i][k]);
			}
		}
	}
	int t1,t2;
	cin>>m;
	for (int i=1;i<=m;++i){
		scanf("%d %d",&t1,&t2);
		printf("%d\n",a[t1][t2]);
	}
	return 0;
}