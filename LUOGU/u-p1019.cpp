#include <bits/stdc++.h>
using namespace tsd;

int n;
char sta,c[25][105],mark[25],ans,len,tmp;

int add(int a,int b){
	int ans=0,l1,l2;
	l1=strlen(c[a]+1);
	l2=strlen(c[b]+1);
	ans=l1+l2;
	for (int i=l1;i>=1;--i){
		for (int j=l2;j>=1;--j)
	}
}

void bfs(char start,int last,int ta){
	bool flag=false;
	for (int i=1;i<=n;++i){
		if (c[i][1]==start&&mark[i]<2&&strcmp(c[i]+1,c[last]+1)!=0){
			mark[i]++;
			flag=true;
			len=strlen(c[i]+1);
			tmp=add(last,i);
			dfs(c[i][len],i,ta+tmp);
			mark[i]--;
		}
	}
	if (!flag) {
		ans=max(ans,ta);
	}
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%s",c[i]+1);
	}
	cin>>sta;
	c[0][1]=sta;
	bfs(sta,0,0);
	return 0;
}