#include <bits/stdc++.h>
using namespace std;

int n,a[200005],sum,ans;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]),ans=min(ans,a[i]);
	for (int i=n;i>=1;i--){
		sum+=a[i];
		ans=max(ans,sum);
		if (sum<0){
			sum=0;
		}
	}
	printf("%d",ans);
	return 0;
}