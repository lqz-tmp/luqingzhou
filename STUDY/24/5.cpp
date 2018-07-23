#include <bits/stdc++.h>
using namespace std;

int n,f[105][105];
char a[105];

int dfs(int st,int en){
	if (st>=en) return 1;
	if (f[st][en]!=-1) return f[st][en];
	int ans=1e9,tmp=0;
	if (a[st]==a[en]) tmp=1;
	for (int k=st;k<=en-1;++k)
		ans=min(ans,dfs(st,k)+dfs(k+1,en)-tmp);
	f[st][en]=ans;
	return ans;
}

int main(){
	int ans;
	while (scanf("%s",a+1)!=EOF){
		n=strlen(a+1);
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				f[i][j]=-1;
		ans=dfs(1,n);
		strcpy(a+1,"");
		cout<<ans<<endl;
	}
	return 0;
}