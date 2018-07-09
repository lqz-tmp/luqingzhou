#include <bits/stdc++.h>
using namespace std;

long long a[100005];

int main(){
	int n,t,te;
	long long tmp;
	cin>>n>>t;
	for (int i=1;i<=n;++i){
		scanf("%d",&te);
		a[i]=a[i-1]+te;
	}
	int l,r,mid,max=0,ai,aj;
	for (int i=1;i<=n;++i){
		l=i;r=n;
		while (l<=r){
			mid=(l+r)/2;
			tmp=a[mid]-a[i-1];
			if (tmp<=t){
				if (mid-i+1>max){
					ai=i;
					aj=mid;
					max=mid-i+1;
					// cout<<ai<<aj<<endl;
					}
				l=mid+1;
				}
				else{
					r=mid-1;
			}
		}
	}
	cout<<ai<<' '<<aj<<endl;
	// for (int i=1;i<=n;++i){
	// 	cout<<a[i]<<endl;
	// }
	return 0;
}