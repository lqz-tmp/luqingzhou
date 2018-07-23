#include <bits/stdc++.h>
using namespace std;

int n,a[35],f[35][35],tmp[35][35],ans;

long long dfs(int st,int en){
	if (st==en) return a[st];
	if (st>en) return 1;
	if (f[st][en]!=-1) return f[st][en];
	long long ans=0,te;
	for (int i=st;i<=en;++i){
		te=dfs(st,i-1)*dfs(i+1,en)+a[i];
		if (te>ans) {
			ans=te;
			tmp[st][en]=i;
		}
	}
	f[st][en]=ans;
	return ans;
}

void print(int l,int r){
	if (l>r) return;
	if (l==r) {
		cout<<l<<' ';
		return;
	}
	cout<<tmp[l][r]<<' ';
	print(l,tmp[l][r]-1);
	print(tmp[l][r]+1,r);
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			f[i][j]=-1;
	ans=dfs(1,n);
	cout<<ans<<endl;
	print(1,n);
	return 0;
}