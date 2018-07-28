#include <bits/stdc++.h>
using namespace std;

struct node
{
	int tx,ty,step,last;
}t1,t2;

int a[1005][1005],mark[1005][1005],mstep[100005],ans,n,m,x,y,ttx,tty,
	dx[4]={1,-1,0,0},
	dy[4]={0,0,1,-1};
char tmp[1005];

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		scanf("%s",tmp+1);
		for (int j=1;j<=n;++j){
			a[i][j]=tmp[j]-'0';
		}
	}
	queue <node> que;
	for (int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		if (mark[x][y]!=0) printf("%d\n",mstep[mark[x][y]]);
		else{
			ans=0;
			t1.tx=x; t1.ty=y; t1.step=0; t1.last=a[x][y]; mark[x][y]=i;
			que.push(t1);
			while (!que.empty()){
				t2=que.front();
				que.pop();
				ans++;
				for (int j=0;j<4;++j){
					ttx=t2.tx+dx[j];
					tty=t2.ty+dy[j];
					if (ttx>=1&&ttx<=n&&tty>=1&&tty<=n&&mark[ttx][tty]==0&&a[ttx][tty]!=t2.last){
						t1.tx=ttx; t1.ty=tty; t1.step=t2.step+1; t1.last=a[ttx][tty]; mark[ttx][tty]=i;
						que.push(t1);
					}
				}
			}
			mstep[i]=ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}