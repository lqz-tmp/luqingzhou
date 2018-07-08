#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,t,ans=0;
	bool a[100005]{false};
	cin>>n>>k;
	int tmp=k;
	for (int i=1;i<=n;++i){
		scanf("%d",&t);
		if (!a[t]){
			a[t]=true;
			tmp--;
			if (tmp==0) {
				ans++;
				tmp=k;
				memset(a,false,sizeof(a));
			}
		}
	}
	cout<<ans+1<<endl;
}