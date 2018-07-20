#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a[10005],x,ans;
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	cin>>x;
	int l,r,mid;
	l=1;r=n;
	while (l<=r){
		mid=(l+r)/2;
		if (a[mid]>=x){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	if (a[ans]==x) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}