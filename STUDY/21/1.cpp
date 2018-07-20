#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,tmp,x,xm;
	cin>>n>>x>>xm;
	for (int i=1;i<=n;++i){
		scanf("%d",&tmp);
		printf("%d ",tmp);
		if (tmp==x) printf("%d ",xm);
	}
	return 0;
}