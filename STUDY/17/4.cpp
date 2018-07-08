#include <bits/stdc++.h>
using namespace std;

int main(){
	int a=1,b=0,k,ta,tb;
	cin>>k;
	for (int i=1;i<=k;++i){
		ta=a;tb=b;
		a=tb;
		b=tb+ta;
	}
	cout<<a<<' '<<b;
	return 0;
}