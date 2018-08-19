#include <bits/stdc++.h>
using namespace std;

struct node{
	long long w,v;
}a[200005];

struct node2{
	long long a,b;
}q[200005];

long long sum[200005],cnt[200005],ans,ml=1e13L;

int main(){
	long long n,m,s;
	long long maxl=0,minl=1e9; 
	cin>>n>>m>>s;
	ml=s;
	for (long long i=1;i<=n;++i){
		scanf("%lld %lld",&a[i].w,&a[i].v);
		maxl=max(maxl,(long long )a[i].w);
		minl=min(minl,(long long )a[i].w);
	}
	for (long long i=1;i<=m;++i){
		scanf("%lld %lld",&q[i].a,&q[i].b);
	}
	long long l=minl-1,r=maxl+2,mid;
	while (l<=r){
		mid=(l+r)/2;
		sum[0]=cnt[0]=0;
		for (long long i=1;i<=n;++i){
			sum[i]=cnt[i]=0;
		}
		for (long long i=1;i<=n;++i){
			sum[i]=sum[i-1];
			cnt[i]=cnt[i-1];
			if (a[i].w>=mid){
				cnt[i]++;
				sum[i]+=a[i].v;
			}
		}
		long long tan=0;
		for (long long i=1;i<=m;++i){
			tan+=(sum[q[i].b]-sum[q[i].a-1])*(cnt[q[i].b]-cnt[q[i].a-1]);
		}
		ml=min(ml,llabs(s-tan));
		ans=mid;
		if (tan>s){
			l=mid+1;
		}else{
			r=mid-1;
		}
		// cout<<mid<<' '<<tan<<' '<<ml<<endl;
	}
	cout<<ml<<endl;
	return 0;
}