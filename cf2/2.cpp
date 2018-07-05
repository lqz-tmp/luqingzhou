#include <bits/stdc++.h>
using namespace std;

int main(){
// 	srand((unsigned)time(NULL));
// for (int j=0;j<=100;j++)
// {	int a,b,x;
// 	a=rand() % 5 +1;
// 	b=rand() % 5 +1;
// 	x=(rand() % 5 +1)*2;
	int a,b,x;
	// cout<<a<<' '<<b<<' '<<x<<'\n';
	cin>>a>>b>>x;
	if (x%2==0&&x/2==a){
		for (int i=1;i<=a;i++){
			cout<<1<<0;
			b--;
		}
		for (int i=1;i<=b;i++){
			cout<<1;
		}
		return 0;
	}
	if (x%2==0){
		cout<<0;
		x--;a--;
	}
	int tmp=(x-1)/2;
	for (int i=1;i<=tmp;i++){
		cout<<1<<0;
		a--;b--;
	}
	for (int i=1;i<=b;i++){
		cout<<1;
	}
	for (int i=1;i<=a;i++){
		cout<<0;
	}
// 	system("pause");
// }
	return 0;
}