#include <bits/stdc++.h>
using namespace std;

struct tree
{
	int a,b;
}t[2005];
int n,m,f[2005];

bool cmp(tree x,tree y){
	return (x.b>y.b);
}

int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&t[i].a);
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&t[i].b);
	}
	sort(t+1,t+n+1,cmp);
	for (int i=1;i<=n;++i){
		for (int j=m;j>=1;--j){
			f[j]=max(f[j],f[j-1]+t[i].a+t[i].b*(j-1));
		}
	}
	cout<<f[m];
    return 0;
}