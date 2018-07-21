#include <bits/stdc++.h>
using namespace std;

int f[105][105][105];

int main(){
	char c1[105],c2[105],c3[105];
	int l1,l2,l3;
	scanf("%s",c1+1);
	scanf("%s",c2+1);
	scanf("%s",c3+1);
	l1=strlen(c1+1);
	l2=strlen(c2+1);
	l3=strlen(c3+1);
	for (int i=1;i<=l1;++i){
		for (int j=1;j<=l2;++j){
			for (int k=1;k<=l3;++k){
				if (c1[i]==c2[j]&&c2[j]==c3[k]) f[i][j][k]=f[i-1][j-1][k-1]+1;
				else {
					f[i][j][k]=max(f[i-1][j][k],f[i][j-1][k]);
					f[i][j][k]=max(f[i][j][k],f[i][j][k-1]);
				}
			}
		}
	}
	cout<<f[l1][l2][l3]<<endl;
	return 0;
}