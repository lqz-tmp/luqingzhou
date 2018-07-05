#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int arr[a][b];
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
			scanf("%d",&arr[i][j]);
	int i,j;
	for (int k = 0; k < b; ++k)
	{
		j=k;i=0;
		while ((i<a)&&(j>=0)){
			printf("%d\n",arr[i][j]);
			j--; i++;
		}
	}
	for (int k = 1; k < a; ++k)
	{
		i=k;j=b-1;
		while ((i<a)&&(j>=0)){
			printf("%d\n",arr[i][j]);
			j--; i++;
		}
	}
	return 0;
}