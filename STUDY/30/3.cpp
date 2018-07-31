#include <bits/stdc++.h>
using namespace std;

int a[1005][1005],ans[100005],tr[1005],n,m,q,tu,tv,t[100005],u[100005],v[100005];

int getroot(int m){
	if (tr[m]==m) return m;
	tr[m]=getroot(tr[m]);
	return tr[m];
}

void add(int l,int r){
	int t1=getroot(l);
	int t2=getroot(r);
	if (t1!=t2){
		tr[t1]=t2;
	}
}

int search(int l,int r){
	int t1=getroot(l);
	int t2=getroot(r);
	if (t1!=t2){
		return 2;
	}else{
		return 1;
	}
}

int main(){
	cin>>n>>m>>q;
	for (int i=1;i<=n;++i)
		tr[i]=i;
	for (int i=1;i<=m;++i){
		scanf("%d %d",&tu,&tv);
		a[tu][tv]++;
		a[tv][tu]++;
	}
	for (int i=1;i<=q;++i){
		scanf("%d %d %d",&t[i],&u[i],&v[i]);
		if (t[i]==1){
			a[u[i]][v[i]]--;
			a[v[i]][u[i]]--;
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (a[i][j]>0) add(i,j);
		}
	}
	for (int i=q;i>=1;--i){
		if (t[i]==1) add(u[i],v[i]);
		else {
			ans[i]=search(u[i],v[i]);
		}
	}
	for (int i=1;i<=q;++i){
		if (ans[i]==1) printf("Yes\n");
		else if (ans[i]==2) printf("No\n");
	}
	return 0;
}