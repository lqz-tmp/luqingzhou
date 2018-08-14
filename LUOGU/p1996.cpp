#include <bits/stdc++.h>
using namespace std;

int Next[1005];

int main(){
	int n,num,cnt=0,now=1;
	cin>>n>>num;
	for (int i=1;i<=n;++i)
		Next[i]=i+1;
	Next[n]=1;
	while (cnt<n){
		int co=1;
		while (co<num-1){
			co++;
			now=Next[now];
		}
		printf("%d ",Next[now]);
		Next[now]=Next[Next[now]];
		now=Next[now];
		cnt++;
	}
	return 0;
}