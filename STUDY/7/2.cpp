#include <iostream>
using namespace std;
int main()
{
	long long a,tmp=0;
	int ans=0,n=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a;
		if (a>tmp){
			ans=i+1;
			tmp=a;
		}
	}
	cout<<ans<<"\n"<<tmp<<endl;
	return 0;
}