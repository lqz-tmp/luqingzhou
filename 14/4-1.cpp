#include <bits/stdc++.h>
using namespace std;
int a[200],f[105][100005],ans,n,k;

void dfs(int x, int y){
	if (y>k) return;
	if (x>n) {
		ans=max(ans, y);
		return;
	}
	if (f[x][y]==1) return;
	f[x][y]=1;
	dfs(x+1,y+a[x]);
	dfs(x+1,y);
}

int main(){
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
	dfs(1,0);
	cout<<ans;
	return 0;
}