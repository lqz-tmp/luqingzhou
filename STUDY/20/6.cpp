#include <bits/stdc++.h>
using namespace std;

long long a[2000];

int main(){
	int n,maxl;
	cin>>n;
	a[0]=1;
	maxl=n*(n+1)/2;
	for (int i=1;i<=n;++i){
		for (int j=maxl;j>=i;--j){
			a[j]=a[j]+a[j-i];
		}
	}
	if (maxl%2==0)
		cout<<a[maxl/2]/2<<endl;
	else cout<<0<<endl;
	return 0;
}