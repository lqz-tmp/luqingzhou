#include <bits/stdc++.h>
using namespace std;

struct farmer{
	int p,a;
}f[5005];

bool cmp(farmer x,farmer y){
	return x.p<y.p;
}

int main(){
	int n,m,tmp,cnt=1;
	long long ans=0;
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		scanf("%d %d",&f[i].p,&f[i].a);
	}
	sort(f+1,f+m+1,cmp);
	while(n>0){
		tmp=min(f[cnt].a,n);
		n-=tmp;
		ans+=(long long)tmp*f[cnt].p;
		cnt++;
	}
	cout<<ans<<endl;
	return 0;
}