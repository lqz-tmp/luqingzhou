#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y,step;
}t1,t2;

int n,m,tx,ty,a[405][405],
	dx[]={-2,-2,-1,-1,1,1,2,2},
	dy[]={-1,1,-2,2,-2,2,-1,1};

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			a[i][j]=-1;
	cin>>tx>>ty;
	queue <node> que;
	t1.x=tx; t1.y=ty; t1.step=0;
	a[tx][ty]=0;
	que.push(t1);
	while (!que.empty()){
		t2=que.front();
		que.pop();
		for (int i=0;i<8;++i){
			int ttx=t2.x+dx[i];
			int tty=t2.y+dy[i];
			if (ttx>=1&&ttx<=n&&tty>=1&&tty<=m&&a[ttx][tty]==-1){
				t1.x=ttx;
				t1.y=tty;
				t1.step=t2.step+1;
				a[ttx][tty]=t2.step+1;
				que.push(t1);
			}
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j)
			cout<<left<<setw(5)<<a[i][j];
		cout<<endl;
	}
	return 0;
}