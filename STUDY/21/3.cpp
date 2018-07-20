#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,n,a[100005],tmp,maxl=0,ans=0;
	cin>>m>>n;
	for (int i=1;i<=m;++i){
		scanf("%d",&a[i]);
		maxl=max(maxl,a[i]);
	}
	int l=1,r=maxl,mid;
	while (l<=r){
		mid=(l+r)/2;
		tmp=0;
		for (int i=1;i<=m;++i)
			tmp+=a[i]/mid;
		if (tmp>=n){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}