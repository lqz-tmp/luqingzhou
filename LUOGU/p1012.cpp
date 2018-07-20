#include <bits/stdc++.h>
using namespace std;

int n;
string s[25];

bool cmp(string a,string b){
	return (a+b>b+a);
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>s[i];
	}
	sort(s+1,s+n+1,cmp);
	for (int i=1;i<=n;++i){
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}