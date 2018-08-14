#include <bits/stdc++.h>
using namespace std;

struct node{
	int st,en,cost;
}e[200000];

int f[305],n,m;

bool cmp(node x,node y){
	return x.cost<y.cost;
}

int getroot(int x){
	if (f[x]==x) return x;
	f[x]=getroot(f[x]);
	return f[x];
}

int main(){
	cin>>n>>m;
	int ans;
	for (int i=1;i<=n;++i)
		f[i]=i;
	for (int i=1;i<=m;++i)
		scanf("%d %d %d",&e[i].st,&e[i].en,&e[i].cost);
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for (int i=1;i<=n-1;++i){
		cnt++;
		int t1=getroot(e[cnt].st);
		int t2=getroot(e[cnt].en);
		if (t1==t2){
			i--;
			continue;
		}
		f[t1]=t2;
		if (i==n-1) ans=e[cnt].cost;
	}
	cout<<n-1<<' '<<ans;
	return 0;
}