#include <bits/stdc++.h>
using namespace std;

int a[35],ans[35],ch[20][2],tmp[11],tans[50],n,m;

void bl(int nn){
	if (tmp[nn]) return;
	tmp[nn]=1;
	for (int i=1;i<=m;++i){
		if (ch[i][1]==nn) bl(ch[i][2]);
	}
}

void times(int n){
	for (int i=1;i<=40;++i)
		tans[i]*=n;
	for (int i=1;i<=40;++i)
		if (tans[i]>9){
			tans[i+1]+=tans[i]/10;
			tans[i]%=10;
		}
}

void print(){
	int len=40;
	for (len=40;tans[len]==0;len--);
	for (int i=len;i>=1;--i){
		cout<<tans[i];
	}
}

int main(){
	tans[1]=1;
	char c;
	int tt=0;
	for (c=getchar();!(c>='0'&&c<='9');c=getchar());
	while (c>='0'&&c<='9'){
		tt++;
		a[tt]=c-'0';
		c=getchar();
	}
	n=tt;
	cin>>m;
	for (int i=1;i<=m;++i)
		cin>>ch[i][1]>>ch[i][2];
	for (int i=1;i<=n;++i){
		int ta=0;
		for (int j=0;j<=9;++j) tmp[j]=0;
		bl(a[i]);
		if (i==1&&tmp[0]==1) tmp[0]=0;
		for (int j=0;j<=9;++j){
			if (tmp[j]) ta++;
		}
		if (ta!=0) times(ta);
		// print();
		// cout<<endl<<ta<<endl;
	}
	print();
	return 0;
}