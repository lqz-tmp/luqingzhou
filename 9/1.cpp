#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j;
	scanf("%d %d %d",&n,&i,&j);
	for (int k = 1; k <=n; ++k)	printf("(%d,%d) ",i,k);
	printf("\n");

	for (int k = 1; k <=n; ++k)	printf("(%d,%d) ",k,j);
	printf("\n");

	int tmp,ti,tj;
	if (i>j) tmp=j-1; else tmp=i-1;
	ti=i-tmp;tj=j-tmp;
	for (int k=0;(ti+k<=n)&&(tj+k<=n);++k) printf("(%d,%d) ",ti+k,tj+k);
	printf("\n");

	if (n-i>j-1) {tj=1;ti=i+j-1;} else {ti=n;tj=j-n+i;};
	for (int k=0;(ti-k>=1)&&(tj+k<=n);++k) printf("(%d,%d) ",ti-k,tj+k);
	return 0;
}