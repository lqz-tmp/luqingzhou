#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,tmp,sum=0;
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&tmp);
		sum^=tmp;
	}
	cout<<sum;
	return 0;
}