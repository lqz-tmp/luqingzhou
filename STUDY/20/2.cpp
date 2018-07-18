#include <bits/stdc++.h>
using namespace std;

int t,n,a[25],ans,s;

void dfs(int i,int num,int sum){
	if (i>n) {
		if (num==n/2) 
			ans=min(ans,abs(2*sum-s));
		return;
	}
	dfs(i+1,num+1,sum+a[i]);
	dfs(i+1,num,sum);
}

int main(){
	cin>>t;
	for (int d=1;d<=t;d++){
		cin>>n;s=0;
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			s+=a[i];
		}
		ans=2000000000;
		dfs(1,0,0);
		cout<<ans<<endl;
	}
    return 0;
}