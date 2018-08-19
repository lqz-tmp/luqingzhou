#include <bits/stdc++.h>
using namespace std;

int tmp[55],a[55][200005],sum[200005];
long long ans;

int main(){
	int n,k,p,co,tv;
	cin>>n>>k>>p;
	for (int i=1;i<=n;++i){
		scanf("%d %d",&co,&tv);
		tmp[co]++;
		a[co][tmp[co]]=i;
		sum[i]=sum[i-1];
		if (tv<=p) sum[i]++;
	}
	for (int i=0;i<=k-1;++i){
		for (int j=1;j<=tmp[i];++j){
			int l=j,r=tmp[i],mid,tan;
			while (l<=r){
				mid=(l+r)/2;
				int tt=0;
				if(a[i][mid]-a[i][j]>0) tt=sum[a[i][mid]]-sum[a[i][j]-1];
				if (tt>=1){
					tan=mid;
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			// cout<<i<<' '<<a[i][j]<<' '<<a[i][tan]<<' '<<tmp[i]<<endl;
			if(tan>j) ans+=tmp[i]-tan+1,cout<<"+1"<<endl;;
		}
	}
	// for (int i=0;i<=k-1;++i){
	// 	// cout<<i<<':'<<"   ";
	// 	// for (int j=1;j<=tmp[i];++j) cout<<a[i][j]<<' ';
	// 	// 	cout<<endl;
	// }
	// for (int i=1;i<=n;++i) cout<<sum[i]<<' ';
	// cout<<endl;
	cout<<ans;
	return 0;
}