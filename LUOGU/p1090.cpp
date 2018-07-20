#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a[20005];
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;i<=n-1;++i){
		ans+=a[i]+a[i+1];
		a[i+1]+=a[i];
		a[i]=0;           //13-15行:累加结果,并进行合并,注意:此时1~i-1均为0
		for (int j=1;j<=n-1;++j){
			if (a[j]>a[j+1]) swap(a[j],a[j+1]);  //由于其他数字是有序的,只要选择排序即可
		}
	}
	cout<<ans<<endl;
	return 0;
}