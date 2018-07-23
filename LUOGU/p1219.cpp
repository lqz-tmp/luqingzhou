#include <bits/stdc++.h>
using namespace std;

int n,cnt,f[15][15],a[40],m1[40],m2[40],m3[40],ans;

void bfs(int i){
	if (i>n){
		if (cnt<3){
			for (int j=1;j<=n;++j){
				cout<<a[j]<<' ';
			}
			cout<<endl;
		}
		cnt++;
		return;
	}
	for (int j=1;j<=n;++j){
		if (m1[j]==0&&m2[i+j]==0&&m3[i-j+n]==0){
			a[i]=j;
			m1[j]=1;
			m2[j+i]=1;
			m3[i-j+n]=1;
			bfs(i+1);
			m1[j]=0;
			m2[i+j]=0;
			m3[i-j+n]=0;
		}
	}
}


int main(){
	cin>>n;
	bfs(1);
	cout<<cnt<<endl;
	return 0;
}