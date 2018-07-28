#include <bits/stdc++.h>
using namespace std;

int a[30005],f[30005],n,m;

int getroot(int x){
	if (f[x]==x) return x;
	f[x]=getroot(f[x]);
	return f[x];
}

void add(int x,int y){
	int t1=getroot(x);
	int t2=getroot(y);
	if (t1==t2) return;
	f[t1]=t2;
	a[t2]+=a[t1];
}

int get(int x){
	int te=getroot(x);
	return a[te];
}

int main(){
	cin>>n>>m;
	for (int i=0;i<n;++i)
		f[i]=i,a[i]=1;
	for (int i=1;i<=m;++i){
		int tmp,a1,an;
		scanf("%d %d",&tmp,&a1);
		for (int j=2;j<=tmp;++j){
			scanf("%d",&an);
			add(a1,an);
		}
	}
	cout<<get(0);
	return 0;
}