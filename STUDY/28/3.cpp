#include <bits/stdc++.h>
using namespace std;

int a[100005],f[100005],n,m;
char tmp;

int getroot(int x){
	if (f[x]==x) return x;
	f[x]=getroot(f[x]);
	return f[x];
}

void add(int x,int y){
	int t1=getroot(x);
	int t2=getroot(y);
	if (t1==t2) return;
	f[t1]=t2;
	a[t2]+=a[t1];
}

int get(int x){
	int te=getroot(x);
	return a[te];
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		f[i]=i,a[i]=1;
	for (int i=1;i<=m;++i){
		tmp=getchar();
		while (tmp!='M'&&tmp!='Q') tmp=getchar();
		if (tmp=='M') {
			int g,b;
			scanf("%d %d",&g,&b);
			add(g,b);
		}else{
			int g;
			scanf("%d",&g);
			printf("%d\n",get(g));
		}
	}
	return 0;
}