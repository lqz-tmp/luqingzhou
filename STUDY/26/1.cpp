#include <bits/stdc++.h>
using namespace std;

int h[1000005],cnt=0;

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

void get(){
	printf("%d\n",h[1]);
	del();
}

int main(){
	int n;
	cin>>n;
	for (int j=1;j<=n;++j){
		char tmp[35];
		scanf("%s",tmp+1);
		if (tmp[1]=='A') {
			int te;
			scanf("%d",&te);
			insert(te);
		}else{
			if (cnt==0) printf("ERROR\n");
			else get();
		}
	}
	return 0;
}