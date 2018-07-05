#include<bits/stdc++.h>
using namespace std;
int ml,k;
string s;
bool pd(int i,int j){
	int tmp=0;
	for (int k=i;k<=(i+j)/2;k++){
		if (s[k]!=s[j-k+i]) tmp++;
	}
	 return (tmp<=k);
}
int main(){
	cin>>s;  cin>>k;
	for (int i=0;i<=s.length()-1;i++){
		for (int j=i;j<=s.length()-1;j++){
			if (pd(i,j)&&(j-i+1>ml)) ml=j-i+1;
		}
	}
	cout<<ml;
	return 0;
}