#include <bits/stdc++.h>
using namespace std;
int a[805],b[30];
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=int(sqrt(800));++i){
		b[i]=i*i;
	}
	a[0]=1;
	for (int i=1;i<=int(sqrt(800));++i){
		for (int j=1;j<=n;++j){
			if(j>=b[i]){
				a[j]+=a[j-b[i]];
			}
		}
	}
	cout<<a[n]<<endl;
	return 0;
}
