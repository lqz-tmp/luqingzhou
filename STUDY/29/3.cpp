#include <bits/stdc++.h>
using namespace std;

struct node{
	int st,en,val;
}a[10005];

int tmp[1005],n,t1,cnt,f[10005],tt,ttt,ans;

void add(int s,int e,int v){
	cnt++;
	a[cnt].st=s;
	a[cnt].en=e;
	a[cnt].val=v;
}

bool cmp(node x,node y){
	return x.val<y.val;
}

int getroot(int x){
	if (f[x]==x) return x;
	f[x]=getroot(f[x]);
	return f[x];
}

bool ins(int a,int b){
	int a1=getroot(a);
	int a2=getroot(b);
	if (a1==a2) return false;
	f[a1]=f[a2];
	ttt+=2;
	return true;
}

int main(){
	cin>>n;
	for (int i=1;i<=n*n;++i){
		a[i].val=1e9;
	}
	for (int i=1;i<=n*n;++i){
		scanf("%d",&t1);
		if (t1==0) continue;
		if (tmp[t1]!=0)
			add(tmp[t1],i,t1);
		else tmp[t1]=i;
	}
	sort(a+1,a+n*n+1,cmp);
	for (int i=1;i<=n*n;++i)
		f[i]=i;
	while (ttt<n){
		tt++;
		if (ins(a[tt].st,a[tt].en)) ans+=a[tt].val;
	}
	cout<<ans<<endl;
	return 0;
}