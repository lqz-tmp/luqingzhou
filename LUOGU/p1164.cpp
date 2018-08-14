#include <bits/stdc++.h>
using namespace std;

int f[10005];

int main(){
	int t,n,a[105];
	cin>>n>>t;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i){
		for (int j=t;j>=1;--j){
			if (j>a[i]){
				f[j]=f[j]+f[j-a[i]];
			}else if(j==a[i]) f[j]=f[j]+1;
		}
	}
	cout<<f[t];
	return 0;
}