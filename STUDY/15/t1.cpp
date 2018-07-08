#include<bits/stdc++.h>
using namespace std;

long long x[1000];

int main() {
	long long a,b,t,temp=0,tmp=0;
	int cn=2,i;
	bool flag;
	cin>>a>>b;
	if (a==b){
		cout<<2;
		return 0;
	}
	tmp=a;temp=b;x[1]=a;x[2]=b;
	while (abs(temp-tmp!=1)){
		flag=false;
		t=temp;
		temp=abs(temp-tmp);
		tmp=t;
		for (i=1;i<=cn;i++){
			if(x[i]==temp){
				flag=true;
				break;
			}
		}
		if (!flag){
			cn++;
			x[cn]=temp;
		}
		cout<<'.';
	}
	// for (i=1;i<=cn;i++){
	// 	if (x[i]<tmp) cn--;
	// }
	cn+=min(tmp,temp)-1;
	cout<<cn;
	return 0; 
}