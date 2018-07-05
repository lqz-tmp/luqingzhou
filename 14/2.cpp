# include<bits/stdc++.h>
using namespace std;

struct per
{
	int a,b;
}x[205];
bool cmp(per m,per n){
	return (m.a>n.a||(m.a==n.a&&m.b<n.b));
}
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d %d",&x[i].a,&x[i].b);
	}
	sort(x+1,x+n+1,cmp);
	int ans;
	for (int i=1;i<=n;i++){
		ans=0;
		for (int j=1;j<i;j++){
			if (x[j].b<x[i].b) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}