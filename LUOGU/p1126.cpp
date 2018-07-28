#include <bits/stdc++.h>
using namespace std;

struct node{
	int tx,ty,step,way;
}t1,t2;

int a[55][55],mark[55][55],n,m,tmp,x,y,nx,ny,cnt,ans=1e9,
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
	for (int i=1;i<=54;++i)
	    for (int j=1;j<=54;++j)
	        mark[i][j]=1e9;
	cin>>x>>y>>nx>>ny>>w;
	x++; y++; nx++; ny++;
	queue <node> que;
	if (a[x][y]==0){
	    if (w=='E') t1.way=1;
		else if (w=='S') t1.way=2;
		else if (w=='W') t1.way=3;
		else t1.way=4;
		t1.tx=x; t1.ty=y; t1.step=0; mark[x][y]=0;
		que.push(t1);
	}
	while (!que.empty()){
		cnt++;
		if (cnt>=1000) return 0;
		t2=que.front();
		que.pop();
		if (t2.tx==nx&&t2.ty==ny){
		    ans=min(ans,t2.step);
		}
		int tw=t2.way,xx=t2.tx,yy=t2.ty,st=t2.step;
		for (int i=3*tw-2;i<=3*tw;i++){
			int ttx=xx+dx[i],tty=yy+dy[i];
			if (ttx>=2&&ttx<n&&tty>=2&&tty<m&&a[ttx][tty]==0&&mark[ttx][tty]>=st+1){
				t1.tx=ttx; t1.ty=tty; t1.step=st+1; t1.way=tw; mark[ttx][tty]=st+1;
				que.push(t1);
			}
			if (a[ttx][tty]==1) break;
		}
		tw++; tw%=4; if (tw==0) tw=4;
		for (int i=3*tw-2;i<=3*tw;i++){
			int ttx=xx+dx[i],tty=yy+dy[i];
			if (ttx>=2&&ttx<n&&tty>=1&&tty<m&&a[ttx][tty]==0&&mark[ttx][tty]>=st+2){
				t1.tx=ttx; t1.ty=tty; t1.step=st+2; t1.way=tw; mark[ttx][tty]=st+2;
				que.push(t1);
			}
			if (a[ttx][tty]==1) break;
		}
		tw=t2.way-1; tw=(tw+4)%4; if (tw==0) tw=4;
		for (int i=3*tw-2;i<=3*tw;i++){
			int ttx=xx+dx[i],tty=yy+dy[i];
			if (ttx>=2&&ttx<n&&tty>=1&&tty<m&&a[ttx][tty]==0&&mark[ttx][tty]>=st+2){
				t1.tx=ttx; t1.ty=tty; t1.step=st+2; t1.way=tw; mark[ttx][tty]=st+2;
				que.push(t1);
			}
			if (a[ttx][tty]==1) break;
		}
	}
	if (ans!=1e9) cout<<ans;
	else cout<<-1;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
