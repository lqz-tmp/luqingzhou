#include <bits/stdc++.h>
using namespace std;

struct per{
	int t;
	char c;
}a[27];

bool cmp(per a,per b){
	return ((a.t>b.t)||(a.t==b.t&&a.c<b.c));
}

int main(){
	string s;
	cin>>s;
	for (int i=0;i<=s.length()-1;++i){
		a[s[i]-'a'+1].t++;
		a[s[i]-'a'+1].c=s[i];
	}
	sort(a+1,a+27,cmp);
	for (int i=1;i<=26;++i){
		if (a[i].t>0) cout<<a[i].c<<' '<<a[i].t<<endl;
	}
	return 0;
}