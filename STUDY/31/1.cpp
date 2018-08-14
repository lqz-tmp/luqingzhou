#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans=0,k;
	double tmp=0;
	cin>>k;
	while (tmp<=k){
		ans++;
		tmp+=1.0/ans;
	}
	cout<<ans;
	return 0;
}