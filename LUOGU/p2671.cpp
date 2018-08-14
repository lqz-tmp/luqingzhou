#include <bits/stdc++.h>
using namespace std;
long long m,n,anum[100005][2],aval[100005][2],cou[100005][2],sqrx[100005][2],arr[100005][3];
int main(){
	cin>>m>>n;
	int p=10007;
	for (int i=1;i<=m;++i){
		scanf("%lld",&arr[i][1]);
	}
	for (int i=1;i<=m;++i){
		scanf("%lld",&arr[i][2]);
	}
	int sum=0;
	for (int i=1;i<=m;++i){
		int color=arr[i][2];
		// if (anum[color][i%2]){
			sum=(sum+cou[color][i%2]*i*arr[i][1])%p;
			sum=(sum+sqrx[color][i%2])%p;
			sum=(sum+anum[color][i%2]*arr[i][1])%p;
			sum=(sum+aval[color][i%2]*i)%p;
		// }
		cou[color][i%2]++;
		sqrx[color][i%2]=(sqrx[color][i%2]+i*arr[i][1])%p;
		anum[color][i%2]=(anum[color][i%2]+i)%p;
		aval[color][i%2]=(aval[color][i%2]+arr[i][1])%p;
	}
	cout<<sum;
	return 0;
}