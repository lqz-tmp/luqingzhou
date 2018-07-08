#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	long long ans=0;
	ans=(n+1)*n/2;
	cout<<ans*2-n<<endl;
	ans*=3;
	cout<<ans;
	return 0;
}