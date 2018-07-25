#include <cstdio>
#include <iostream>
using namespace std;

struct point{
	int x,y,color,step;
}que[10005],tmp;

int q[105][105],mark[105][105];
int m,n,a,b,c,le,ri,
    dx[4]={1,-1,0,0},
    dy[4]={0,0,1,-1};

int main(){
	cin>>m>>n;
	for (int i=1;i<=n;++i){
		scanf("%d %d %d",&a,&b,&c);
		q[a][b]=c+1;
	}
	le=0;ri=1;
	que[ri].x=1;que[ri].y=1;que[ri].color=q[1][1];que[ri].step=0,mark[1][1]=1;
	while (le<ri){
		tmp=que[le+1];
		le++;
		for (int i=0;i<4;++i){
			if (tmp.x+dx[i]>=1&&tmp.x+dx[i]<=m&&tmp.y+dy[i]>=1&&tmp.y+dy[i]<=m&&mark[tmp.x+dx[i]][tmp.y+dy[i]]==0&&(tmp.color==q[tmp.x][tmp.y]||q[tmp.x+dx[i]][tmp.y+dy[i]]!=0)){
				mark[tmp.x+dx[i]][tmp.y+dy[i]]=1;
				ri++;
				que[ri].x=tmp.x+dx[i];
				que[ri].y=tmp.y+dy[i];
				if(q[tmp.x+dx[i]][tmp.y+dy[i]]==tmp.color){
					que[ri].color=tmp.color;
					que[ri].step=tmp.step;
				}else if(q[tmp.x+dx[i]][tmp.y+dy[i]]!=0){
					que[ri].color=q[tmp.x+dx[i]][tmp.y+dy[i]];
					que[ri].step=tmp.step+1;
				}else{
					que[ri].color=tmp.color;
					que[ri].step=tmp.step+2;
				}
			}
		}
	}
	// cout<<-1;
	int minl=1e9;
	for (int i=1;i<=ri;++i)
		if (que[i].x==m&&que[i].y==m) minl=min(minl,que[i].step);
	cout<<minl;
	return 0;
}