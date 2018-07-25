#include <bits/stdc++.h>
using namespace std;

struct node{
	int ti,di;
}a[50005];

int h[50005],cnt=0,tmp;

void up(int i){
	while (i/2>0){
		int j=i/2;
		if (h[j]<h[i])
			swap(h[i],h[j]);
		i=j;
	}
}

void down(int i){
	while (i*2<=cnt){
		int j=i*2,k=i*2+1;
		if (k>cnt || h[j]>h[k]) k=j;
		if (h[i]<h[k]) swap(h[i],h[k]);
		i=k;
	}
}

void insert(int x){
	cnt++;
	h[cnt]=x;
	up(cnt);
}

void del(){
	h[1]=h[cnt];
	cnt--;
	down(1);
}

void get(){
	tmp=h[1];
	del();
}

bool cmp(node x,node y){
	return x.di<y.di;
}

int main(){
	int n,hp,thp;
	long long sum=0;
	cin>>n>>hp;
	thp=hp;
	for (int i=1;i<=n;++i){
		scanf("%d %d",&a[i].ti,&a[i].di);
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;++i){
		insert(a[i].ti);
		sum+=a[i].ti;
		while (sum>a[i].di){
			thp--;
			get();
			sum-=tmp;
		}
	}
	if (thp>0) cout<<hp-thp<<endl;
	else cout<<-1<<endl;
	return 0;
}