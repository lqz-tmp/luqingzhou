#include <bits/stdc++.h>
using namespace std;

int n,p;

void dfs(int n){
	if (n==0) return;
	int ans;
	if (n>0||n%p==0){
		dfs(n/p);
		ans=n%p;
	}else{
		dfs(n/p+1);
		ans=n%p-p;
	}
	if (ans<10) cout<<ans;
	else cout<<(char)(ans-10+'A');
}

int main(){
	cin>>n>>p;
	cout<<n<<'=';
	dfs(n);
	cout<<"(base"<<p<<')';
	return 0;
}