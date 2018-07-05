#include <bits/stdc++.h>  //D-2
using namespace std;
int a[200], f[105][100005];
int main(){
	int n, k;
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
	    for (int j = 1; j <= k; ++j)
	    	if (j>=a[i])
	        f[i][j]=max(f[i-1][j], f[i-1][j-a[i]]+a[i]);
	    	else
	    	f[i][j]=f[i-1][j];
	cout<<f[n][k];
	return 0;
}