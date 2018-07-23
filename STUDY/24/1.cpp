#include <bits/stdc++.h>
using namespace std;

int n,m,a[205],cost[205][205],f[205][205],tmp;

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n-1;++i){
		for (int j=i+1;j<=n;++j){
			tmp=a[(i+j)/2];
			for (int k=i;k<=j;++k){
				cost[i][j]+=abs(a[k]-tmp);
			}
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j)
			f[i][j]=1e9;
		f[i][1]=cost[1][i];
	}
	for (int i=2;i<=m;++i){
		for (int j=i;j<=n;++j){
			for (int k=j+1;k<=n;++k){
				f[k][i]=min(f[k][i],cost[j+1][k]+f[j][i-1]);
			}
		}
	}
	cout<<"Total distance sum = "<<f[n][m]<<endl;
	return 0;
}