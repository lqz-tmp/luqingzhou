#include <bits/stdc++.h>
using namespace std;

int n,m,t,sx,sy,ex,ey,tx,ty,ans,a[10][10],
    wx[4]={0,0,1,-1},
    wy[4]={1,-1,0,0};

void dfs(int x,int y){
	if (x==ex&&y==ey){
		ans++;
		return;
	}else{
		a[x][y]=1;
		for (int i=0;i<4;++i){
			int tx=x+wx[i];
			int ty=y+wy[i];
			if (tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==0){
				dfs(tx,ty);
				// a[tx][ty]=0;
			}
		}
	}
	a[x][y]=0;
}

int main(){
	cin>>n>>m>>t;
	cin>>sx>>sy>>ex>>ey;
	for (int i=1;i<=t;++i){
		cin>>tx>>ty;
		a[tx][ty]=1;
	}
	dfs(sx,sy);
	cout<<ans<<endl;
	return 0;
}