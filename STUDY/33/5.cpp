#include <bits/stdc++.h>
using namespace std;

int a[50005];
int L,n,m,ans;

int solve(int t){
	int t1=0,t2=0;
	for (int i=1;i<=n;++i){
		if (a[i]-t1<t) t2++;
		else{
			t1=a[i];
		}
	}
	return t2;
}

int main(){
	cin>>L>>n>>m;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	int l=1,r=L,mid;
	while (l<=r){
		mid=(r+l)/2;
		int tmp=solve(mid);
		if (tmp<=m){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}