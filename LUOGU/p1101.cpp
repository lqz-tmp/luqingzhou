#include <bits/stdc++.h>
using namespace std;

int n,b[105][105],c[105][105],
    wx[8]={1,1,1,-1,-1,-1,0,0},
    wy[8]={-1,0,1,-1,0,1,-1,1};
char a[105][105];

void check(int x,int y){
	switch (a[x][y]){
		case 'y':
			b[x][y]=1;
			break;
		case 'i':
			b[x][y]=2;
			break;
		case 'z':
			b[x][y]=3;
			break;
		case 'h':
			b[x][y]=4;
			break;
		case 'o':
			b[x][y]=5;
			break;
		case 'n':
			b[x][y]=6;
			break;
		case 'g':
			b[x][y]=7;
			break;
		default :
			b[x][y]=0;
	}
}

void dfs(int x,int y,int way,int step){
	// cout<<x<<' '<<y<<' '<<way<<' '<<step<<endl;
	if (x<1||y<1||x>n||y>n||b[x][y]!=step) return;
	if (step==7){
		for (int i=1;i<=7;++i){
			c[x][y]=1;
			x-=wx[way];
			y-=wy[way];
		}
		return;
	}
	dfs(x+wx[way],y+wy[way],way,step+1);
	return;
}

int main(){
	scanf("%d\n",&n);
	for (int i=1;i<=n;++i){
		scanf("%s",a[i]+1);
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			check(i,j);
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (b[i][j]==1){
				for (int k=0;k<8;++k){
					dfs(i,j,k,1);
				}
			}
		}
	}
	// dfs(1,2,7,1);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (c[i][j]==1){
				printf("%c",a[i][j]);
			}else printf("%c",'*');
		}
		printf("\n");
	}
	return 0;
}