#include <bits/stdc++.h>
using namespace std;

int main(){
	int m[30],n;
	cin>>n;
	m[0]=1;
	m[2]=3;
	for (int i=4;i<=n;i+=2){
		m[i]=4*m[i-2]-m[i-4];
	}
	cout<<m[n]<<endl;
	return 0;
}