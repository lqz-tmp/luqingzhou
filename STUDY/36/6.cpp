#include <bits/stdc++.h>
using namespace std;

long long a[1000000];

int main(){
	int n,k,fl=0;
	cin>>n>>k;
	for (int i=1;i<=n;++i){
		for (int j=i-1;j>=1&&j>=i-k;--j){
			a[i]+=a[j];
		}
		a[i]+=i;
		if (a[i]>=1234567890){
			cout<<a[i];
			fl=1;
			break;
		}
	}
	if (!fl) cout<<a[n];
	return 0;
}