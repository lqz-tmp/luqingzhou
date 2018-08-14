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
	cin>>n;
	int ans=0;
	m=n;
	for (int i=0;i<=n;++i)
		f[i]=i;
	for (int i=1;i<=n;++i){
		e[i].st=0;
		e[i].en=i;
		scanf("%d",&e[i].cost);
	}
	int t;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			m++;
			scanf("%d",&t);
			e[m].st=i;
			e[m].en=j;
			e[m].cost=t;
		}
	}
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for (int i=1;i<=n;++i){
		cnt++;
		int t1=getroot(e[cnt].st);
		int t2=getroot(e[cnt].en);
		if (t1==t2){
			i--;
			continue;
		}
		f[t1]=t2;
		ans+=e[cnt].cost;
	}
	cout<<ans;
	return 0;
}