#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,ans=0,tmp,sum=0,k;
	cin>>n>>k;
	for (int i=1;i<=n;++i){
		scanf("%d",&tmp);
		if (sum+tmp<=k) sum+=tmp;
		else {
			ans++;
			sum=tmp;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}