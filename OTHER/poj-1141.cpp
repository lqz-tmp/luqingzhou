#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,f[205][205],tmp[205][205],tans;
char a[205];

bool check(int x,int y){
	return ((a[x]=='['&&a[y]==']')||(a[x]=='('&&a[y]==')'));
}

void print(int st,int en){
	if (st==en) {
		if (a[st]=='[') cout<<"[]";
		else cout<<"()";
		return;
	}
	if (st>en) return;
	if (tmp[st][en]==-1){
		cout<<a[st];
		print(st+1,en-1);
		cout<<a[en];
		return ;
	}
	print (st,tmp[st][en]);
	print (tmp[st][en]+1,en);
}

int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for (int len=2;len<=n;len++){
		for (int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			if (check(i,j)) f[i][j]=2+f[i+1][j-1],tmp[i][j]=-1;
			for (int k=i;k<=j-1;++k){
				tans=f[i][k]+f[k+1][j];
				if (tans>f[i][j]){
					f[i][j]=tans;
					tmp[i][j]=k;
				}
			}
		}
	}
	print(1,n);
	return 0;
}