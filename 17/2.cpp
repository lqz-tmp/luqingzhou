#include <bits/stdc++.h>
using namespace std;

int main(){
	int k,n,time=210,cnt;
	cin>>k>>n;
	cnt=k;
	int t;
	char tc;
	for (int i=1;i<=n;++i){
		scanf("%d %c",&t,&tc);
		// if (tc!='P') 
		time-=t;
		if (time<0) break;
		if (tc=='T') cnt++;
	}
	cnt%=8;
	if (cnt==0) cnt=8;
	cout<<cnt<<endl;
	return 0;
}