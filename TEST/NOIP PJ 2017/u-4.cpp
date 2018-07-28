#include <bits/stdc++.h>
using namespace std;

struct node{
	int l,v;
}a[500005];

long long k,f[500005],ans=-1;
int maxl,minl,n,d;

bool check(){
	for (int i=1;i<=n;++i){
		f[i]=-1e9;
	}
	int en=-1;
	long long ans=0;
	for (int i=1;i<=n;++i){
		int l=0,r=i,mid;
		while (l<=r){
			mid=(l+r)/2;
			if (a[mid].l<=a[i].l-minl){
				l=mid+1;
				en=mid;
			}else{
				r=mid-1;
			}
		}
		for (int j=en;j>=0;--j){
			if (a[j].l<a[i].l-maxl) break;
			f[i]=max(f[i],f[j]+a[i].v);
		}
		// cout<<i<<' '<<en<<' '<<f[i]<<endl;
		ans=max(ans,f[i]);
	}
	return (ans>=k);
}

int main(){
	cin>>n>>d>>k;
	for (int i=1;i<=n;++i){
		scanf("%d %d",&a[i].l,&a[i].v);
	}
	int l=1,r=a[n].l,mid;
	while (l<=r){
		mid=(l+r)/2;
	// mid=1;
		maxl=mid+d;
		minl=max(1,d-mid);
		// cout<<maxl<<' '<<minl<<endl;
		if (check()){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}