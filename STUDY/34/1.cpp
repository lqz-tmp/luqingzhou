#include <bits/stdc++.h>
using namespace std;

struct node{
	int a,b,g,k;
}tmp[100005];

int main(){
	int n,x,y;
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d %d %d %d",&tmp[i].a,&tmp[i].b,&tmp[i].g,&tmp[i].k);
	cin>>x>>y;
	int ans=0;
	for (int i=1;i<=n;++i){
		if (tmp[i].a<=x&&tmp[i].b<=y&&tmp[i].a+tmp[i].g>=x&&tmp[i].b+tmp[i].k>=y) ans=i;
	}
	cout<<ans;
	return 0;
}