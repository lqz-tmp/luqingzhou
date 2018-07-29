#include <cstdio>
#include <iostream>
using namespace std;

int n,sum,a[14][14],mark[14],ta[14],flag=false;

void init(){
	for (int i=1;i<=n;++i){
		a[i][1]=a[i][i]=1;
		for (int j=2;j<=i-1;++j)
			a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
}

void print(){
	for (int i=1;i<=n;++i) 
		printf("%d ",ta[i]);
}

void dfs(int st,int ans){
	if (flag) return ;
	if (st>n){
		if (ans!=sum) return ;
		print();
		flag=true;
		return ;
	}
	if (ans>=sum) return ;
	for (int i=1;i<=n;++i){
		if (mark[i]==0){
			mark[i]=1;
			ta[st]=i;
			dfs(st+1,ans+i*a[n][st]);
			mark[i]=0;
		}
	}
}

int main(){
	scanf("%d %d",&n,&sum);
	init();
	dfs(1,0);
	return 0;
}