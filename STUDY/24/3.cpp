#include <bits/stdc++.h>
using namespace std;

int n,f[205][205];
char a[205];

bool check(int x,int y){
	return ((a[x]=='['&&a[y]==']')||(a[x]=='('&&a[y]==')'));
}

int dfs(int st,int en){
	if (st>=en) return 0;
	if (f[st][en]!=-1) return f[st][en];
	int ans=0;
	if (check(st,en)) ans=2+dfs(st+1,en-1);
	for (int k=st;k<=en-1;++k)
		ans=max(ans,dfs(st,k)+dfs(k+1,en));
	f[st][en]=ans;
	return ans;
}

int main(){
	int ans;
	scanf("%s",a+1);
	n=strlen(a+1);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			f[i][j]=-1;
	ans=dfs(1,n);
	cout<<ans<<endl;
	return 0;
}