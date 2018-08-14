#include <bits/stdc++.h>
using namespace std;

struct node{
	int st,en,cost;
}e[20005];

int f[20005],val[20005],n,m,st,en,cost;
long long ans;

int getroot(int x){
	if (f[x]==x) return x;
	f[x]=getroot(f[x]);
	return f[x];
}

bool cmp(node x,node y){
	return x.cost<y.cost;
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i)
		f[i]=i,val[i]=1;
	for (int i=1;i<=n-1;++i){
		scanf("%d %d %d",&e[i].st,&e[i].en,&e[i].cost);
	}
	sort(e+1,e+n,cmp);
	for (int i=1;i<=n-1;++i){
		int t1=getroot(e[i].st),t2=getroot(e[i].en);
		ans+=e[i].cost;
		ans+=(long long)(val[t1]*val[t2]-1)*(long long)(e[i].cost+1);
		f[t1]=t2;
		val[t2]+=val[t1];
	}
	cout<<ans;
	return 0;
}