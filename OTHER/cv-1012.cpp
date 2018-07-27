#include <iostream>
#include <cmath>
using namespace std;

bool is(int a,int b){
	while (1){
		int t=a%b;
		if (t==0) break;
		else {
			a=b;
			b=t;
		}
	}
	return (b==1);
}

int main(){
	int x,y;
	cin>>x>>y;
	if (y%x!=0) {
		cout<<0<<endl;
		return 0;
	}
	x=y/x;
	int ans=0;
	int len=int(sqrt(x));
	for (int i=1;i<=len;++i){
		if (x%i==0&&is(i,x/i)){
			ans+=1;
			if (i!=x/i) ans+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}