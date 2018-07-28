#include <bits/stdc++.h>
using namespace std;

struct node{
	int tx,ty,step,way;
}t1,t2;

int a[55][55],mark[55][55],n,m,tmp,x,y,nx,ny,cnt,
	dx[]={0,0,0,0,1,2,3,0,0,0,-1,-2,-3},
	dy[]={0,1,2,3,0,0,0,-1,-2,-3,0,0,0};
char w;

int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			scanf("%d",&tmp);
			if (tmp==1){
				a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=1;
			}
		}
	}
	n++; m++;
	cin>>x>>y>>nx>>ny>>w;
	x++; y++; nx++; ny++;
	queue <node> que;
	if (a[x][y]==0){
		t1.tx=x; t1.ty=y; t1.step=0; mark[x][y]=1;
		if (w=='E') t1.way=1;
		else if (w=='S') t1.way=2;
		else if (w=='W') t1.way=3;
		else t1.way=4;
		que.push(t1);
	}
	while (!que.empty()){
		cnt++;
		if (cnt>=1000) return 0;
		t2=que.front();
		que.pop();
		cout<<t2.tx<<' '<<t2.ty<<' '<<t2.step<<' '<<t2.way<<endl;
		if (t2.tx==nx&&t2.ty==ny){
			cout<<t2.step<<endl;
			// break;
			return 0;
		}
		int tw=t2.way,xx=t2.tx,yy=t2.ty,st=t2.step;
		for (int i=3*tw-2;i<=3*tw;i++){
			int ttx=xx+dx[i],tty=yy+dy[i];
			if (ttx>=2&&ttx<=n&&tty>=2&&tty<=m&&a[ttx][tty]==0&&mark[ttx][tty]==0){
				t1.tx=ttx; t1.ty=tty; t1.step=st+1; t1.way=tw; mark[ttx][tty]=1;
				que.push(t1);
			}
			if (a[ttx][tty]==1) break;
		}
		tw++; tw%=4; if (tw==0) tw=4;
		if (a[xx+dx[tw*3-2]][yy+dy[tw*3-2]]==0&&mark[xx+dx[tw*3-2]][yy+dy[tw*3-2]]==0)
		{
			t1.way=tw;
			t1.step=st+1;
			t1.tx=xx;
			t1.ty=yy;
			que.push(t1);
		}
		tw=t2.way-1; tw=(tw+4)%4; if (tw==0) tw=4;
		if (a[xx+dx[tw*3-2]][yy+dy[tw*3-2]]==0&&mark[xx+dx[tw*3-2]][yy+dy[tw*3-2]]==0)
		{
			t1.way=tw;
			t1.step=st+1;
			t1.tx=xx;
			t1.ty=yy;
			que.push(t1);
		}
	}
	cout<<-1;
	// for (int i=1;i<=n;++i){
	// 	for (int j=1;j<=m;++j){
	// 		cout<<a[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}
