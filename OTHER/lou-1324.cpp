#include <bits/stdc++.h>
using namespace std;

int a[105][105];
char c[105];
int wx[4]={0,0,1,-1},
    wy[4]={1,-1,0,0};
int main(){
	int n,m,ti,tj;
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		scanf("%s",c+1);
		for (int j=1;j<=m;++j){
			a[i][j]=c[j]-'0';
		}
	}
	int ans=0;
	queue <int> qi;
	queue <int> qj;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			if (a[i][j]){
				ans++;
				a[i][j]=0;
				qi.push(i);
				qj.push(j);
				while (!qi.empty()){
					ti=qi.front();
					tj=qj.front();
					qi.pop();
					qj.pop();
					for (int k=0;k<4;++k){
						if (a[ti+wx[k]][tj+wy[k]]){
							a[ti+wx[k]][tj+wy[k]]=0;
							qi.push(ti+wx[k]);
							qj.push(tj+wy[k]);
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}