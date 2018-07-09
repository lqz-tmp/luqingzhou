#include <bits/stdc++.h>
using namespace std;

int a[105],b[105];

int main(){
	int n,cn,tmp,ta,tb;
	cin>>n;
	cn=n;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[a[i]]=1;
	}
	for (int i=1;i<=cn;++i){
		for (int j=1;j<=cn;++j){
			if (i==j) continue;
			ta=min(a[i],a[j]);
			tb=max(a[i],a[j]);
			tmp=tb/ta;
			if (b[tmp]==0) {
				b[tmp]=1;
				cn++;
				a[cn]=tmp;
			}
		}
	}
	int ans=0;
	for (int i=0;i<=100;++i){
		if (b[i]==1) ans++;
	}
	cout<<ans;
	return 0;
}