#include <bits/stdc++.h>
using namespace std;

struct pr{
	int ti,tj,x,y; //x:last way,y:last steps
}que[10005],tmp;

int n,m,a[105][105],f[105][105],le,ri,x1,yy1,x2,y2,tx,ty,
	dx[4]={1,-1,0,0},
	dy[4]={0,0,1,-1};

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
			f[i][j]=1e9;
		}
	cin>>x1>>yy1>>x2>>y2;
	le=0;ri=0;
	for (int i=0;i<4;++i){
		tx=x1;ty=yy1;
		while (x1+dx[i]>=1&&x1+dx[i]<=n&&yy1+dy[i]>=1&&yy1+dy[i]<=n&&a[x1+dx[i]][yy1+dy[i]]==0&&f[x1+dx[i]][yy1+dy[i]]==1e9){
			ri++;
			que[ri].x=i;
			que[ri].y=0;
			que[ri].ti=x1+dx[i];
			que[ri].tj=yy1+dy[i];
			x1+=dx[i];
			yy1+=dy[i];
		}
		x1=tx;yy1=ty;
	}
	while (le<ri){
		tmp=que[le+1];
		le++;
		f[tmp.ti][tmp.tj]=min(tmp.y,f[tmp.ti][tmp.tj]);
		if (tmp.ti==x2&&tmp.tj==y2) {
			cout<<tmp.y;
			return 0;
		}
		for (int i=0;i<4;++i){
			tx=tmp.ti;ty=tmp.tj;
			while (tmp.ti+dx[i]>=1&&tmp.ti+dx[i]<=n&&tmp.tj+dy[i]>=1&&tmp.tj+dy[i]<=m&&a[tmp.ti+dx[i]][tmp.tj+dy[i]]==0&&f[tmp.ti+dx[i]][tmp.tj+dy[i]]==1e9){
				ri++;
				que[ri].x=i;
				que[ri].y=tmp.y+(int)(i!=tmp.x);
				que[ri].ti=tmp.ti+dx[i];
				que[ri].tj=tmp.tj+dy[i];
				tmp.ti+=dx[i];
				tmp.tj+=dy[i];
			}
			tmp.ti=tx;tmp.tj=ty;
		}
	}
	return 0;
}