#include <bits/stdc++.h>
using namespace std;

void dfs(int n){
	if (n==0){
		cout<<0;
		return ;
	}
	int a[20],cnt=0;
	while (n!=0){
		cnt++;
		a[cnt]=n%2;
		n/=2;
	}
	// cout<<cnt<<endl;
	for (int i=cnt;i>=1;--i){
		if (a[i]==0) continue;
		if (i!=cnt) cout<<'+';
		if (i==2) {cout<<2;continue;}
		cout<<"2(";
		dfs(i-1);
		cout<<')';
	}
}

int main(){
	int n;
	cin>>n;
	dfs(n);
	return 0;
}