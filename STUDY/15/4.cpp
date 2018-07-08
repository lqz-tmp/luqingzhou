#include <bits/stdc++.h>
using namespace std;
int a[805],b[30];
int main(){
	int n;
	cin>>n;
	for (int i=1;i*i<=n;++i){
		b[i]=i*i;
	}
	a[0]=1;
	for (int i=1;i*i<=n;++i){
		for (int j=1;j<=n;++j){
			if(j>=b[i]){
				a[j]+=a[j-b[i]];
			}
		}
	}
	cout<<a[n]<<endl;
	return 0;
}

/*
for (int i=1;i*i<=n;++i){
	for (int j=1;j<=n;++j){
		if(j>=b[i]){
			a[i][j]=a[i-1][j]+a[i][j-b[i]];
		}
	}
}
*/