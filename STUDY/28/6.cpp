#include <bits/stdc++.h>
using namespace std;

int f[50005],v[50005],n,m,ans;

int getroot(int x){
	if (f[x]==x) return x;
	int tmp=f[x];
	f[x]=getroot(f[x]);
	v[x]=(v[x]+v[tmp])%3;
	return f[x];
}

void add(int x,int y,int len){
	int t1=getroot(x);
	int t2=getroot(y);
	if (t1==t2){
		return;
	}
	f[t1]=t2;
	v[t1]=(v[y]+len-v[x])%3;
}

bool check(int len,int x,int y){
	if (x>n||y>n) return false;
	if (len==1&&x==y) return false;
	if (getroot(x)==getroot(y))
		return ((v[x]-v[y])%3+3)%3==len;
	return true;
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		f[i]=i;
	for (int i=1;i<=m;++i){
		int len,x,y;   //len==0 a==b,len==1 a>b,len==2 a<b
		scanf("%d %d %d",&len,&x,&y);
		len--;         //!!len==0表示同类
		if (check(len,x,y)){
			add(x,y,len);
		}else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}