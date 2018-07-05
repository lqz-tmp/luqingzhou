#include <bits/stdc++.h>
using namespace std;

int a[11][11],b[11][11];
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	a[5][5]=m;
	for (int i = 0; i < n; ++i){
		for (int j = 1; j <= 9; ++j)
			for (int k = 1; k <= 9; ++k)
				b[j][k]=2*a[j][k]+a[j-1][k]+a[j-1][k-1]+a[j-1][k+1]+a[j][k+1]+a[j][k-1]+a[j+1][k]+a[j+1][k+1]+a[j+1][k-1];
		memcpy(a, b, sizeof(b));
	}
	for (int j = 1; j <10; ++j){
		for (int k = 1; k <10; ++k) printf("%d ",a[j][k]);
			printf("\n");
	}
	return 0;
}