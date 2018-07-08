#include <bits/stdc++.h>  //D-2
using namespace std;
int a[200], f[100005];
int main(){
	int n, k;
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
	    for (int j = k; j >= 1; --j)
	    	if (j>=a[i])
	        f[j]=max(f[j], f[j-a[i]]+a[i]);
	    	else
	    	f[j]=f[j];
	cout<<f[k];
	return 0;
}