#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y,v;
}tmp[1000];

int m,n,k,a[50][50],cnt,t1,t2,t3,t4,ans;

bool cmp(node a,node b){
	return a.v>b.v;
}

int solve(int x1,int y1,int x2,int y2){
	return (abs(x1-x2)+abs(y1-y2));
}

int main(){
	cin>>m>>n>>k;
	for (int i=1;i<=m;++i)
		for (int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			if (a[i][j]){
				cnt++;
				tmp[cnt].x=i;
				tmp[cnt].y=j;
				tmp[cnt].v=a[i][j];
			}
		}
	sort(tmp+1,tmp+cnt+1,cmp);
	t1=tmp[1].x;
	t2=tmp[1].y;
	k-=t1+1;
	if (k>=t1) ans+=tmp[1].v;
	int cn=1;
	while (k>0&&cn<cnt){
		cn++;
		t3=tmp[cn].x;
		t4=tmp[cn].y;
		k-=solve(t1,t2,t3,t4)+1;
		t1=t3;
		t2=t4;
		if (k>=t1) ans+=tmp[cn].v;
	}
	cout<<ans;
	return 0;
}