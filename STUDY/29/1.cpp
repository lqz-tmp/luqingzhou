#include <bits/stdc++.h>
using namespace std;

int head[100005],Next[100005],a[100005],d[100005],cnt,n,m,t1,t2,ta;

void add(int st,int en){
	cnt++;
	Next[cnt]=head[st];
	head[st]=cnt;
	a[cnt]=en;
}

void bl(int st){
	d[st]=1;
	for (int i=head[st];i!=-1;i=Next[i]){
		bl(a[i]);
		d[st]+=d[a[i]];
	}
	if (d[st]==m+1) ta++;
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		head[i]=-1;
	for (int i=1;i<=n-1;++i){
		scanf("%d %d",&t1,&t2);
		add(t1,t2);
	}
	bl(1);
	cout<<ta;
    return 0;
}