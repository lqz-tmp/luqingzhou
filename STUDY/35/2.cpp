#include <bits/stdc++.h>
using namespace std;

int a[2005][2005],b[2005],t[2005];

void add(int t1,int t2,int t3){
	a[t1][t2]=min(a[t1][t2],t3);
}

int main(){
	int n,m,t1,t2,t3;
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			a[i][j]=1e9;
	for (int i=1;i<=m;++i){
		scanf("%d %d %d",&t1,&t2,&t3);
		add(t1,t2,t3);
		add(t2,t1,t3);
	}
	for (int i=1;i<=n;++i)
		t[i]=a[1][i];
	for (int i=1;i<=n-1;++i){
		int ml=1e9,id=1;
		for (int j=1;j<=n;++j){
			if (b[j]==0&&ml>t[j]){
				ml=t[j];
				id=j;
			}
		}
		b[id]=1;
		for (int j=1;j<=n;++j){
			if (b[j]==0)
			t[j]=min(t[j],t[id]+a[id][j]);
		}
	}
	if (t[n]!=1e9) cout<<t[n];
	else cout<<-1;
	return 0;
}