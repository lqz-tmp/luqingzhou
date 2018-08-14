#include <bits/stdc++.h>
using namespace std;

int tmp[100005];

int main(){
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=k;++i)
		tmp[i]=1;
	for (int i=2;i<=n;++i){
		for (int j=1;j<=k&&i-j>=1;++j){
			tmp[i]=(tmp[i-j]+tmp[i])%100003;
		}
	}
	cout<<tmp[n];
	return 0;
}