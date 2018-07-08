#include <bits/stdc++.h>
using namespace std;

int Data[20005],Next[20005];

int main(){
	int num,cnt,n,m,now,pre,tmp;
	cin>>n>>m>>num;
	for (int i=1;i<=n;++i){
		Data[i]=i;
		Next[i]=i+1;
	}
	Next[n]=1;
	now=n;
	cnt=0;
	for (int i=1;i<=m;++i){
		cnt=0;
		while (cnt<num){
			cnt++;
			pre=now;
			now=Next[now];
		}
		printf("%d\n",Data[now]);
		tmp=now;
		Next[pre]=Next[now];
		while (cnt<2*num){
			cnt++;
			pre=now;
			now=Next[now];
		}
		Next[tmp]=Next[now];
		Next[now]=tmp;
		now=Next[now];
	}
	return 0;
}