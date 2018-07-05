#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a[105]{0},tmp;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>tmp;
		a[tmp]++;
	}
	int ans=0;
	for (int i=1;i<=100;i++){
		if (a[i]>ans) ans=a[i];
	}
	cout<<ans;
	return 0;
}