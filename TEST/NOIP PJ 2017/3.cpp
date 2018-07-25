#include<bits/stdc++.h>
using namespace std;

int f[105][105][3],q[105][105],mark[105][105];
int m,n,x,y,c,pd=0,
    dx[4]{0,0,1,-1},
    dy[4]{1,-1,0,0};

int walk(int a,int b,int color,bool fl){
	if (a==m&&b==m) {
		pd=1;
		return 0;
	}
	if (f[a][b][color]!=-1) return f[a][b][color];
	mark[a][b]=1;
	int tmp=1e9,te=0,tc;
	for (int i=0;i<4;++i){
		if (!(mark[a+dx[i]][b+dy[i]]==0&&a+dx[i]>=1&&a+dx[i]<=m&&b+dy[i]>=1&&b+dy[i]<=m&&(q[a+dx[i]][b+dy[i]]!=0||fl))) continue;
		if (q[a+dx[i]][b+dy[i]]==0) te=2,tc=color;
		else if (q[a+dx[i]][b+dy[i]]!=color) te=1,tc=q[a+dx[i]][b+dy[i]];
		else te=0,tc=color;
		tmp=min(tmp,walk(a+dx[i],b+dy[i],tc,(te!=2))+te);
	}
	mark[a][b]=0;
	// if (tmp==0) tmp=1e9;
	f[a][b][color]=tmp;
	return tmp;
}


int main(){
	cin>>m>>n;
	for (int i=1;i<=n;++i){
		scanf("%d %d %d",&x,&y,&c);
		q[x][y]=c+1;
	}
	for (int i=1;i<=m;++i){
		for (int j=1;j<=m;++j){
			for (int k=0;k<3;++k)
				f[i][j][k]=-1;
		}
	}
	int ans=walk(1,1,q[1][1],true);
	if (pd) cout<<ans;
	else cout<<-1;
	return 0;
}