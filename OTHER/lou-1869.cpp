#include <bits/stdc++.h>
using namespace std;

int t,m,n,f[15][15];

int main(){
	cin>>t;
	for (int x=1;x<=t;++x){
		cin>>m>>n;
		for (int i=1;i<=m;++i){
			for (int j=1;j<=n;++j){
				f[i][j]=0;
			}
		}
		for (int i=1;i<=m;++i)
			f[i][1]=1;
		for (int i=1;i<=n;++i)
			f[0][i]=1;
		for (int i=1;i<=m;++i){
			for (int j=2;j<=n;++j){
				if (i>=j) f[i][j]=f[i][j-1]+f[i-j][j];
				else f[i][j]=f[i][i];
			}
		}
		cout<<f[m][n]<<endl;
	}
	return 0;
}