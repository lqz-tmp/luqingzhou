#include <bits/stdc++.h>
using namespace std;

int n,k,p,a[20005];

int main(){
	scanf("%d %d %d",&n,&k,&p);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	
	return 0;
}