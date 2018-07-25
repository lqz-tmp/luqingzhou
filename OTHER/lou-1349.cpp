#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n,f[205][205];
char a[205];

bool check(int x,int y){
	return ((a[x]=='['&&a[y]==']')||(a[x]=='('&&a[y]==')'));
}
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for (int len=2;len<=n;len++){
		for (int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			if (check(i,j)) f[i][j]=2+f[i+1][j-1];
			for (int k=i;k<=j-1;++k){
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
			}
		}
	}
	cout<<n+n-f[1][n]<<endl;
	return 0;
}