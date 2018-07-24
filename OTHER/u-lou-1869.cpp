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
		f[0][0]=1;
		for (int i=1;i<=m;++i){
			f[i][i]=1;
			for (int j=1;j<=n&&j<=i;++j){
				f[i][j]=f[i-j][j]+f[i][j-1];
			}
		}
		cout<<f[m][n]<<endl;
	}
	return 0;
}