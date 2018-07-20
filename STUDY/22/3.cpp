#include <bits/stdc++.h>
using namespace std;

int main(){
	int tmp,t,n,a[100005],le,ri;
	le=0;ri=0;
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&tmp);
		if (tmp==1){
			scanf("%d",&t);
			ri++;
			a[ri]=t;
		}else if (tmp==2){
			le++;
		}else{
			printf("%d\n",a[le+1]);
		}
	}
	return 0;
}