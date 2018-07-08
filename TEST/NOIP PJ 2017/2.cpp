#include<bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
	int n,q,t,tmp,te,flag;
	cin>>n>>q;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=q;++i){
		scanf("%d %d",&t,&tmp);
		te=pow(10,t);
		flag=0;
		for (int i=1;i<=n;++i){
			if (a[i]%te==tmp) {
				flag=1;
				printf("%d\n",a[i]);
				break;
			}
		}
		if (flag==0) printf("-1\n");
	}
	return 0;
}