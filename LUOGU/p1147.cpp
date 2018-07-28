#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll k2,m;
	cin>>m;
	m<<=1;
	for (int k1=sqrt(m);k1>1;--k1){
		if (m%k1==0 && (m/k1+k1)%2==1){
			k2=m/k1;
			cout<<(k2-k1+1)/2<<' '<<(k1+k2-1)/2<<endl;
		}
	}
	return 0;
}