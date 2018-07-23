#include <bits/stdc++.h>
using namespace std;

int n,mark[25],ans,len,tmp;
char sta,c[25][105];

int add(int a,int b){
	int ans=0,l1,l2;
	bool tb=true;
	l1=strlen(c[a]+1);
	l2=strlen(c[b]+1);
	for (int i=1;i<=min(l1,l2);++i){
		tb=true;
		for (int j=1;j<=i;++j){
			if (c[a][l1-i+j]!=c[b][j]) tb=false;
		}
		if (tb) {
			ans=l2-i;
			break;
		}
	}
	return ans;
}

void dfs(int last,int ta){
	bool flag=false;
	for (int i=1;i<=n;++i){
		int ty=add(last,i);
		if (ty>0&&mark[i]<2){
			mark[i]++;
			flag=true;
			len=strlen(c[i]+1);
			dfs(i,ta+ty);
			mark[i]--;
		}
	}
	if (!flag) {
		ans=max(ans,ta);
	}
}

void solve(){
	for (int i=1;i<=n;++i){
		if (c[i][1]==sta){
			mark[i]++;
			len=strlen(c[i]+1);
			dfs(i,len);
			mark[i]--;
		}
	}
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%s",c[i]+1);
	}
	cin>>sta;
	solve();
	cout<<ans<<endl;
	return 0;
}