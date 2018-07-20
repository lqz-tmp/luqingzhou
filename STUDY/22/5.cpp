#include <bits/stdc++.h>
using namespace std;

int wx[4]={0,0,1,-1};
int wy[4]={1,-1,0,0};
char c[2005][2005];
int mark[2005][2005];

int main(){
	int n,m,tx,ty,ts,x,y;
	char t[2005];
	cin>>n>>m;
	queue <int> qx;
	queue <int> qy;
	queue <int> qs;
	for (int i=1;i<=n;++i){
		scanf("%s",t+1);
		for (int j=1;j<=m;++j){
			c[i][j]=t[j];
		}
	}
	qx.push(1);
	qy.push(1);
	qs.push(0);
	mark[1][1]=1;
	while (!qx.empty()){
		tx=qx.front();
		ty=qy.front();
		ts=qs.front();
		qx.pop();
		qy.pop();
		qs.pop();
		// cout<<tx<<' '<<ty<<' '<<ts<<endl;
		if (tx==n&&ty==m) { cout<<ts<<endl; break; }
		for (int i=0;i<=3;++i){
			x=tx+wx[i];
			y=ty+wy[i];
			if (mark[x][y]==0&&c[x][y]=='.'&&x>=1&&y>=1&&x<=n&&y<=m){
				mark[x][y]=1;
				qx.push(x);
				qy.push(y);
				qs.push(ts+1);
			}
		}
	}
	// cout<<qx.size()<<endl;
	return 0;
}