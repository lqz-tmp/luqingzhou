#include <bits/stdc++.h>
using namespace std;

int a[100005],tree[400005],n,m,x,y,z;

void build(int le,int ri,int m){
	if (le==ri){
		tree[m]=a[le];
		return ;
	}
	int mid=(le+ri)/2;
	build(le,mid,m*2);
	build(mid+1,ri,m*2+1);
	tree[m]=min(tree[m*2],tree[m*2+1]);
}

int get(int le,int ri,int nl,int nr,int rt){
	if (le==nl&&ri==nr) return tree[rt];
	int mid=(le+ri)/2,te;
	if (nr<=mid) te=get(le,mid,nl,nr,rt*2);
	else if (nl>=mid+1) te=get(mid+1,ri,nl,nr,rt*2+1);
	else te=min( get(le,mid,nl,mid,rt*2) , get(mid+1,ri,mid+1,nr,rt*2+1) );
	return te;
}

void change(int le,int ri,int m,int ne,int y){
	if (le==ri) {
		tree[m]=y;
		return;
	}
	int mid=(le+ri)/2;
	if (ne<=mid) change(le,mid,m*2,ne,y);
	if (ne>=mid+1) change(mid+1,ri,m*2+1,ne,y);
	tree[m]=min(tree[m*2],tree[m*2+1]);
}

int main(){
	cin>>m>>n;
	for (int i=1;i<=m;++i){
		scanf("%d",&a[i]);
	}
	build(1,m,1);
	for (int i=1;i<=n;++i){
		scanf("%d%d%d",&x,&y,&z);
		if (x==1){
			int ans;
			ans=get(1,m,y,z,1);
			printf("%d ",ans);
		}else{
			change(1,m,1,y,z);
		}
	}
	return 0;
}