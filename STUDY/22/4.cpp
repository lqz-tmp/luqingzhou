#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int m,n,tmp,le,ri,flag,ans=0;
	le=0;ri=0;
	cin>>m>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&tmp);
		flag=1;
		for (int i=le+1;i<=ri;++i){
			if (a[i]==tmp) flag=0;
		}
		if (flag==1){
			ans++;
			if (ri<m){
				ri++;
				a[ri]=tmp;
			}else{
				ri++;
				a[ri]=tmp;
				le++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}