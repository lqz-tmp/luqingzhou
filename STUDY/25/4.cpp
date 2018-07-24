#include <bits/stdc++.h>
using namespace std;
struct go
{
	int t,c;
}a[2005];
int n,cnt,cn,ans,tmp;
long long f[2005];

int main(){
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d %d",&a[i].t,&a[i].c);
	for (int i=1;i<=n;++i)
			f[i]=1e13;
	for (int i=1;i<=n;++i){
		a[i].t++;
		for (int j=n;j>=0;--j){
			tmp=j+a[i].t;
			if (tmp>n) tmp=n;
			f[tmp]=min(f[tmp],f[j]+a[i].c);
		}
	}
	cout<<f[n]<<endl;
	return 0;
}