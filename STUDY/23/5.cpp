#include <bits/stdc++.h>
using namespace std;

struct aty{
	int st,en;
}a[1005];

bool cmp(aty x,aty y){
	return x.en<y.en;
}

int main(){
	int n,tmp=-100,ans=0;
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d %d",&a[i].st,&a[i].en);
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;++i){
		if (a[i].st>tmp){
		ans++;
		tmp=a[i].en;
	}
	}
	cout<<ans<<endl;
	return 0;
}