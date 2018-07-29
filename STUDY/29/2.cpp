#include <bits/stdc++.h>
using namespace std;
#define M 100005


int head[M],Next[M],a[M],c[M],intime[M],outtime[M],cnt,n,m,t1,t2,t3,ta2,dfst;
long long dep[M],ta;

void add(int st,int en,int val){
	cnt++;
	Next[cnt]=head[st];
	head[st]=cnt;
	a[cnt]=en;
	c[cnt]=val;
}

void bl(int st,int pre){
	dfst++;
	intime[st]=dfst;
	for (int i=head[st];i!=-1;i=Next[i]){
		if (a[i]==pre) continue;
		dep[a[i]]+=dep[st]+c[i];
		bl(a[i],st);
	}
	dfst++;
	outtime[st]=dfst;
}

bool check(int t1,int t2){
	return (intime[t2]>=intime[t1]&&outtime[t2]<=outtime[t1]);
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		head[i]=-1;
	for (int i=1;i<=n-1;++i){
		scanf("%d %d %d",&t1,&t2,&t3);
		add(t1,t2,t3);
		add(t2,t1,t3);
	}
	bl(1,0);

	for (int i=1;i<=m;++i){
		scanf("%d %d",&t1,&t2);
		if (check(t1,t2)){
			ta2++;
			ta+=abs(dep[t1]-dep[t2]);
		}
	}
	cout<<ta2<<endl<<ta;
    return 0;
}