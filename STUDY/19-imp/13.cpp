#include <bits/stdc++.h>
using namespace std;

int tx[4]={-1,0,0,1};
int ty[4]={0,1,-1,0};

int n,m;
char c[2005][2005];
int f[2005][2005];
bool b[2005][2005];

int bl(int x,int y){
	if (x>=n&&y>=m) return 0;
	b[x][y]=false;
	// cout<<x<<' '<<y<<endl;
	if (f[x][y]!=0) return f[x][y];
	int tmp=1000000000;
	for (int i=0;i<=3;++i){
		if ((c[x+tx[i]][y+ty[i]]=='.')&&b[x+tx[i]][y+ty[i]])
			tmp=min(tmp,bl(x+tx[i],y+ty[i])+1);
	}
    b[x][y]=true;
	f[x][y]=tmp;
	return tmp;
}

int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    string s;
    cin>>n>>m;
    n=min(2001,n);
    m=min(2001,m);
    getchar();
    memset(b,true,sizeof(b));
    for (int i=0;i<=m+1;++i){
        c[0][i]='*';
        c[n+1][i]='*';
    }
    for (int i=1;i<=n;++i){
    	// cin>>s;
    	for (int j=1;j<=m;++j){
    		c[i][j]=getchar();
    	}
        c[i][0]='*';
        c[i][m+1]='*';
    	getchar();
    }
    int ans=bl(1,1);
    if (ans==1000000000) cout<<-1<<endl;
    else cout<<ans<<endl;
    // for (int i=0;i<=n+1;++i){
    //     for (int j=0;j<=m+1;++j){
    //         cout<<c[i][j];
    //     }
    //     cout<<endl;
    // }
    return 0;
}