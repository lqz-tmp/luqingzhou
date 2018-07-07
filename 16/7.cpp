#include<bits/stdc++.h>
using namespace std;

char a[2005][2005];
bool b[2005][2005]{false}; //是否遍历过
int c[2005][2005];
int m,n;

void bl(int x,int y){
    b[x][y]=true;
    if (a[x-1][y]=='.'&&!b[x-1][y]) bl(x-1,y);
    if (a[x][y-1]=='.'&&!b[x][y-1]) bl(x,y-1);
    if (a[x+1][y]=='.'&&!b[x+1][y]) bl(x+1,y);
    if (a[x][y+1]=='.'&&!b[x][y+1]) bl(x,y+1);
    return;
}

void check(int x,int y){
    for (int i=1;x-i>=1;++i){
        if (a[x-i][y]=='G') c[x][y]++;
        if (a[x-i][y]=='#') break;
    }
    for (int i=1;y-i>=1;++i){
        if (a[x][y-i]=='G') c[x][y]++;
        if (a[x][y-i]=='#') break;
    }
    for (int i=1;x+i<=n;++i){
        if (a[x+i][y]=='G') c[x][y]++;
        if (a[x+i][y]=='#') break;
    }
    for (int i=1;y+i<=m;++i){
        if (a[x][y+i]=='G') c[x][y]++;
        if (a[x][y+i]=='#') break;
    }
}

int main(){
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    string ts;
    for (int i=1;i<=n;++i){
        cin>>ts;
        for (int j=0;j<=ts.length()-1;++j){
            a[i][j+1]=ts[j];
        }
    }
    bl(x,y);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (a[i][j]=='.') check(i,j);
        }
    }
    int ml=0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (b[i][j]&&c[i][j]>ml) ml=c[i][j];
        }
    }
    cout<<ml;
    return 0;
}