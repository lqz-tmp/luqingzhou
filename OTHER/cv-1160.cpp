#include <iostream>
using namespace std;

int a[105][105],dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};

int main(){
	int n,ti,tj,way=0,cnt=1;
	cin>>n;
	tj=ti=(n+1)/2;
	a[ti][tj]=1;
	for (int i=1;i<=2*n-1;++i){
		for (int j=1;j<=(i+1)/2;++j){
			ti+=dx[way%4];
			tj+=dy[way%4];
			cnt++;
			a[ti][tj]=cnt;
		}
		way++;
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	int ans=0;
	for (int i=1;i<=n;++i){
		ans+=a[i][i];
		ans+=a[i][n-i+1];
	}
	ans-=a[n/2+1][n/2+1];
	cout<<ans<<endl;
	return 0;
}