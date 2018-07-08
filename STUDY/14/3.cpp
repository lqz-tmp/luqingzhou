#include <bits/stdc++.h>
using namespace std;
int a[20][20], f[20][17005], mark[20], sum[20], tmp;
int n, ans;

void dfs(int x, int y){
	if (x>n) ans=max(ans, y);
	if (ans>=y+sum[x]) return;
	if (f[x][y]==1) ans=max(ans, y);
	f[x][y]=1;
	for (int i = 1;i <= n; ++i){
		if (mark[i]==0){
			mark[i]=1;
			dfs(x+1, y+a[x][i]);
			mark[i]=0;
		}
	}
}

int maxl(int x){
	for (int i = 1;i <=n; ++i)
		if (a[x][i]>tmp) tmp=a[x][i];
	return tmp;
}

int main(){
	cin>>n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) 
			cin>>a[i][j];
	for (int i = n; i >= 1; --i)
		sum[i]=sum[i+1]+maxl(i);
	dfs(1, 0);
	cout<<ans;
	return 0;
}