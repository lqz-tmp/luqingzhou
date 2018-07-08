#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,t1,t2;
long long k;
int main(){
	cin>>n>>m>>k;
	if (k<=n-1) {
		i=k+1;j=1;
	}else{
		k-=n;
		t1=k%(2*m-2);
		t2=k/(2*m-2);
		if (t1<=m-2) {
			j=t1+2;
			i=n-t2*2;
		}
		else if (t1<=2*m-3){
			t1-=m-2;
			j=m-t1+1;
			i=n-1-t2*2;
		}else{
			i=n-2-t2*2;
			j=2;
		}
	}
	cout<<i<<" "<<j<<endl;
	return 0;
}