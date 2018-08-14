#include <bits/stdc++.h>
using namespace std;

int a[27][100005];

int main(){
	int t;
	cin>>t;
	for (int o=1;o<=t;++o){
		int n,q;
		cin>>n>>q;
		char c;
		memset(a,sizeof(a),0);
		c=getchar();
		while (!(c>='A'&&c<='Z')){
			c=getchar();
		}
		int i=0;
		while (c>='A'&&c<='Z'){
			i++;
			for (int j=1;j<=26;++j){
				a[j][i]=a[j][i-1];
			}
			a[c-'A'+1][i]++;
			c=getchar();
		}
		printf("Case #%d:\n",o);
		for (int j=1;j<=q;++j){
			int l,r;
			scanf("%d %d",&l,&r);
			for (int k=1;k<=26;++k){
				int tmp=a[k][r]-a[k][l-1];
				if (tmp==0) continue;
				printf("%d\n",tmp);
				break;
			}
		}
	}
	return 0;
}