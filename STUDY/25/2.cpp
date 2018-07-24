#include <iostream>
using namespace std;

int n,ans,f[1005][4];

int main(){
	cin>>n;
	f[1][0]=f[1][1]=1;
	f[1][2]=f[1][3]=0;
	for (int i=2;i<=n;++i){
		f[i][0]=(f[i-1][0]+f[i-1][2])%55555;
		f[i][1]=(f[i-1][0]+f[i-1][2])%55555;
		f[i][2]=(f[i-1][1]+f[i-1][3])%55555;
		f[i][3]=(f[i-1][1])%55555;
	}
	cout<<(f[n][0]+f[n][1]+f[n][2]+f[n][3])%55555<<endl;
	return 0;
}