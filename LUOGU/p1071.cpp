#include <bits/stdc++.h>
using namespace std;

int a[27],mark[27];
bool flag=true;
char c1,c2;

int main(){
	string s1,s2,s3,s4="";
	cin>>s1>>s2>>s3;
	for (int i=0;i<=s1.length()-1;++i){
		c1=s1[i];
		c2=s2[i];
		if (a[c1-'A'+1]==0){
			a[c1-'A'+1]=c2-'A'+1;
			if (mark[c2-'A'+1]!=0) flag=false;
			else mark[c2-'A'+1]=1;
		}else if (a[c1-'A'+1]!=c2-'A'+1){
			flag=false;
			break;
		}
	}
	for (int i=1;i<=26;++i){
		if (a[i]==0) flag=false;
	}
	for (int i=0;i<=s3.length()-1;++i){
		s4+=a[s3[i]-'A'+1]+'A'-1;
	}
	if (flag) cout<<s4<<endl;
	else cout<<"Failed"<<endl;
	return 0;
}