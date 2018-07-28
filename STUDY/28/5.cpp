#include <bits/stdc++.h>
using namespace std;

int f[10005],n,m;

int getroot(int x){
	if (f[x]==x) return x;
	f[x]=getroot(f[x]);
	return f[x];
}

void add(int x,int y){
	int t1=getroot(x);
	int t2=getroot(y);
	if (t1==t2){
		return;
	}
	f[t1]=t2;
}

bool check(int x,int y){
	int t1=getroot(x);
	int t2=getroot(y);
	int t3=getroot(x+n);
	int t4=getroot(y+n);
	return (t1==t3||t2==t4);
}

int main(){
	cin>>n>>m;
	for (int i=0;i<2*n;++i)
		f[i]=i;
	for (int i=1;i<=m;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		add(x,y+n);
		add(x+n,y);
		if (check(x,y)){
			cout<<i<<endl;
			return 0;
		} 
	}
	cout<<"OK";
	return 0;
}