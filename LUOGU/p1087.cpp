#include <bits/stdc++.h>
using namespace std;

int a[2000],tree[2000];
char tmp[2000];

void build(int l,int r,int m){
	if (l==r) {
		if (a[l]==1) tree[m]=1;
		else tree[m]=0;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,m*2);
	build(mid+1,r,m*2+1);
	if (tree[m*2]==1&&tree[m*2+1]==1) tree[m]=1;
	else if (tree[m*2]==0&&tree[m*2+1]==0) tree[m]=0;
	else tree[m]=2;
}

void print(int l,int r,int m){
	if (l==r){
		if (tree[m]==1) printf("I");
		else if (tree[m]==0) printf("B");
		else printf("F");
		return;
	}
	int mid=(l+r)/2;
	print(l,mid,m*2);
	print(mid+1,r,m*2+1);
	if (tree[m]==1) printf("I");
	else if (tree[m]==0) printf("B");
	else printf("F");
}

int main(){
	int n;
	cin>>n;
	scanf("%s",tmp+1);
	for (int i=1;i<=pow(2,n);++i){
		a[i]=tmp[i]-'0';
	}
	build(1,pow(2,n),1);
	print(1,pow(2,n),1);
	return 0;
}