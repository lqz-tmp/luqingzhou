#include <bits/stdc++.h>
using namespace std;

int n,k,a[25],ans;

bool check(int n){
	for (int i=2;i<=sqrt(n);++i){
		if (n%i==0) return 0;
	}
	return 1;
}

void dfs(int st,int step,int sum){
	if (step==k){
		if (check(sum)) ans++;
		return;
	}
	for (int i=st+1;i<=n-k+step+1;++i){
		dfs(i,step+1,sum+a[i]);
	}
}

int main(){
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}