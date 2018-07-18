#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,w1,w2,n,v[505],m[505],f[10005];
	cin>>t;
	for (int i=1;i<=t;++i){
		cin>>w1>>w2;
		cin>>n;
		for (int j=1;j<=n;++j){
			scanf("%d %d",&v[j],&m[j]);
		}
		f[0]=0;
		for (int j=1;j<=w2-w1;j++) f[j]=2000000000;
		for (int j=1;j<=n;++j){
			// if ()
			for (int k=w2-w1;k>=m[j];k--){
				if (f[k-m[j]]!=2000000000){
					f[k]=max(f[k],f[k-m[j]]+v[j]);
				}
			}
		}
		if (f[n]!=2000000000) cout<<"The minimum amount of money in the piggy-bank is "<<f[n]<<'.'<<endl;
		else cout<<"This is impossible."<<endl;
	}
    return 0;
}