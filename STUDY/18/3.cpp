#include <bits/stdc++.h>
using namespace std;

int a[500005],b[500005];



int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	// if (n<=10000){
		int ans=0;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n-1;++j){
				if (a[j]>a[j+1]){
					swap(a[j],a[j+1]);
					ans++;
				}
			}
		}
	// }else{

	// }
	cout<<ans;
	return 0;
}