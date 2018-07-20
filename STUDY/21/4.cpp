#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,n,a[100005];
	long long ans,maxl=0,tmp;
	cin>>m>>n;
	for (int i=1;i<=m;++i){
		scanf("%d",&a[i]);
		maxl=max(maxl,(long long)a[i]);
	}
	long long l=1,r=maxl*n,mid;
	while (l<=r){
		mid=(l+r)/2;
		tmp=0;
		for (int i=1;i<=m;++i)
			tmp+=mid/a[i];
		if (tmp>=n){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}