#include <bits/stdc++.h>
using namespace std;

long long a[100005],n,m,y,z;
long long tree[400005],add[400005];
char x;
void build(long long le,long long ri,long long m){
	if (le==ri){
		tree[m]=a[le];
		return ;
	}
	long long mid=(le+ri)/2;
	build(le,mid,m*2);
	build(mid+1,ri,m*2+1);
	tree[m]=tree[m*2]+tree[m*2+1];
}

inline void down(long long m,long long le,long long ri){
	add[m*2]+=add[m];
	add[m*2+1]+=add[m];
	tree[m]+=add[m]*(ri-le+1);
	add[m]=0;
}

inline void up(long long m,long long le,long long ri){
	long long mid=(le+ri)/2;
	// long long t=tree[m];
	tree[m]=tree[m*2]+tree[m*2+1]+add[m*2]*(mid-le+1)+add[m*2+1]*(ri-mid);
	// if (t!=tree[m]) cout<<le<<' '<<ri<<' '<<tree[m]<<" up"<<endl;
}

long long get(long long le,long long ri,long long nl,long long nr,long long rt){
	down(rt,le,ri);
	if (le==nl && ri==nr){
		return tree[rt];
	}
	long long mid=(le+ri)/2;
	long long te;
	if (nr<=mid) te=get(le,mid,nl,nr,rt*2);
	else if (nl>=mid+1) te=get(mid+1,ri,nl,nr,rt*2+1);
	else te=get(le,mid,nl,mid,rt*2)+get(mid+1,ri,mid+1,nr,rt*2+1);
	up(rt,le,ri);
	return te;
}

void change(long long le,long long ri,long long m,long long nl,long long nr,long long y){
	down(m,le,ri);
	if (le==nl && ri==nr) {
		add[m]+=y;
// 		tree[m]+=add[m]*(ri-le+1);
		// cout<<"++"<<y<<' '<<le<<' '<<ri<<' '<<add[m]<<endl;
		return;
	}
	// cout<<le<<' '<<ri<<' '<<m<<endl;
	long long mid=(le+ri)/2;
	if (nr<=mid) change(le,mid,m*2,nl,nr,y);
	else if (nl>=mid+1) change(mid+1,ri,m*2+1,nl,nr,y);
	else change(le,mid,m*2,nl,mid,y) , change(mid+1,ri,m*2+1,mid+1,nr,y);
	up(m,le,ri);
}

int main(){
	cin>>m>>n;
	for (long long i=1;i<=m;++i){
		scanf("%lld",&a[i]);
	}
	build(1,m,1);
	for (long long i=1;i<=n;++i){
		x=getchar();
		while (x!='Q'&&x!='C') x=getchar();
		scanf("%lld %lld",&y,&z);
		if (x==2){
			long long ans;
			ans=get(1,m,y,z,1);
			printf("%lld\n",ans);
		}else{
			long long tmp;
			scanf("%lld",&tmp);
			change(1,m,1,y,z,tmp);
		}
		// for (long long i=1;i<=4*m;++i) cout<<tree[i]<<' ';
			// cout<<endl;
	}
	return 0;
}