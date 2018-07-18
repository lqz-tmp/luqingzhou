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
			for (int k=m[j];k<=w2-w1;++k){
				if (f[k-m[j]]!=2000000000){
					f[k]=min(f[k],f[k-m[j]]+v[j]);
				}
			}
		}
		if (f[w2-w1]!=2000000000) cout<<"The minimum amount of money in the piggy-bank is "<<f[w2-w1]<<'.'<<endl;
		else cout<<"This is impossible."<<endl;
	}
	// for (int i=1;i<=w2-w1;++i) cout<<f[i]<<endl;
    return 0;
}