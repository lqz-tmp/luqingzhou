#include <bits/stdc++.h>
using namespace std;


int main(){
	int x=0,y=0,t,n;
	char tmp[10];
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%s",tmp+1);
		scanf("%d",&t);
		if (tmp[1]=='E') x+=t;
		else if (tmp[1]=='W') x-=t;
		else if (tmp[1]=='N') y+=t;
		else if (tmp[1]=='S') y-=t;
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}