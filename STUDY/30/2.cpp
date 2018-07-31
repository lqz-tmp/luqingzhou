#include <bits/stdc++.h>
using namespace std;

long long a,k,p,s=1,ans,t;

long long po(long long m){
	long long tta=a,ans=1;
	while (m>0){
		if (m%2==1) ans=ans*tta%p;
		m/=2;
		tta=tta*tta%p;
	}
	return ans;
}

long long pow(long long m){
	if (m<=0) return 1;
	if (m==1) return a%p;
	long long ta=1;
	ta=ta*(po(m/2)+1)%p;
	ta=ta*pow(m/2)%p;
	if (m%2==1) {
		ta=(ta+po(m))%p;
	}
	m/=2;
	return ta;
}

int main(){
	cin>>a>>k>>p;
	ans=pow(k);
	cout<<ans;
	return 0;
}