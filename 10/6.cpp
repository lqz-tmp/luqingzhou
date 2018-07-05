#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; ++i){
		scanf("%d",&a[i]);
	}
	double ans=100.0;
	for (int i = 0; i < n-1; ++i)
		if (a[i]>a[i+1])
			ans=ans*a[i]/a[i+1];
	printf("%.1lf",ans);
	return 0;
}