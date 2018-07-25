#include <bits/stdc++.h>
using namespace std;

struct per{
	int num;
	char name[25];
}h[100005];

int cnt=0;
char tmpna[25];
void up(int i){
	while (i/2>0){
		int j=i/2;
		if (h[j].num<h[i].num)
			swap(h[i],h[j]);
		i=j;
	}
}

void down(int i){
	while (i*2<=cnt){
		int j=i*2,k=i*2+1;
		if (k>cnt || h[j].num>h[k].num) k=j;
		if (h[i].num<h[k].num) swap(h[i],h[k]);
		i=k;
	}
}

void insert(int x){
	cnt++;
	h[cnt].num=x;
	strcpy(h[cnt].name+1,tmpna+1);
	up(cnt);
}

void del(){
	swap(h[1],h[cnt]);
	cnt--;
	down(1);
}

void get(){
	printf("%s %d\n",h[1].name+1,h[1].num);
	del();
}

int main(){
	int n;
	cin>>n;
	for (int j=1;j<=n;++j){
		char tmp[35];
		scanf("%s",tmp+1);
		if (tmp[2]=='u'){
			int te;
			scanf("%s %d",tmpna+1,&te);
			insert(te);
		}else{
			if (cnt==0) printf("none\n");
			else get();
		}
	}
	return 0;
}