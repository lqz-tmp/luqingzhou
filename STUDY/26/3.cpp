#include <bits/stdc++.h>
using namespace std;

int h[10005],cnt=0;

void up(int i){
	while (i/2>0){
		int j=i/2;
		if (h[j]>h[i])
			swap(h[i],h[j]);
		i=j;
	}
}

void down(int i){
	while (i*2<=cnt){
		int j=i*2,k=i*2+1;
		if (k>cnt || h[j]<h[k]) k=j;
		if (h[i]>h[k]) swap(h[i],h[k]);
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

int get(){
	int ta=h[1];
	del();
	return ta;
}

int main(){
	int n,ans=0,t1,t2;
	cin>>n;
	for (int i=1;i<=n;++i){
		int te;
		scanf("%d",&te);
		insert(te);
	}
	for (int i=1;i<=n-1;++i){
		t1=get();
		t2=get();
		ans+=t1+t2;
		t1+=t2;
		insert(t1);
	}
	cout<<ans;
	return 0;
}