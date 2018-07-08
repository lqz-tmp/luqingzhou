#include<bits/stdc++.h>
using namespace std;

int f[105][105][3],q[105][105];
int m,n,x,y,c,pd=0;

int walk(int a,int b,int color,bool fl){
	if (a==m&&b==m) {
		pd=1;
		return 0;
	}
	if (f[a][b][color]!=0) return f[a][b][color];
	int tmp=99999999;
	if (a<m){
		if (q[a+1][b]==color) tmp=min(tmp,walk(a+1,b,color,true));
		else if (q[a+1][b]!=0) tmp=min(tmp,walk(a+1,b,q[a+1][b],true)+1);
		else if (fl){
			tmp=min(tmp,walk(a+1,b,color,false)+2);
		}
	}
	if (b<m){
		if (q[a][b+1]==color) tmp=min(tmp,walk(a,b+1,color,true));
		else if (q[a][b+1]!=0) tmp=min(tmp,walk(a,b+1,q[a][b+1],true)+1);
		else if (fl){
			tmp=min(tmp,walk(a,b+1,color,false)+2);
		}
	}
	f[a][b][color]=tmp;
	return tmp;
}


int main(){
	cin>>m>>n;
	for (int i=1;i<=n;++i){
		scanf("%d %d %d",&x,&y,&c);
		q[x][y]=c+1;
	}
	int ans;
	ans=walk(1,1,q[1][1],true);
	// if (pd==0){
	// 	cout<<-1<<endl;
	// 	return 0;
	// }
	// cout<<ans<<endl;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++){
			cout<<q[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}