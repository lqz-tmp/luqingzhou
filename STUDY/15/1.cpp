#include <bits/stdc++.h>
using namespace std;

string a[10005];
int ans,n;

int main(){
	cin>>n;
	getchar();
	for (int i=1;i<=n;i++){
		getline(cin,a[i]);
		for (int j=0;j<=a[i].length()-1;j++){
			if (a[i][j]==' ') ans++;
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=a[i].length()-1;j++){
			if (a[i][j]!=' ')
				printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
