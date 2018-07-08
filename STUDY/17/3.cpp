#include <bits/stdc++.h>
using namespace std;

char c[55][55];
int a[55][55];
int V[8]={1,1,1,-1,-1,-1,0,0};
int L[8]={1,-1,0,1,-1,0,1,-1};



int main(){
	int r,s;
	string ts;
	cin>>r>>s;
	for (int i=1;i<=r;++i){
		cin>>ts;
		for (int j=0;j<=ts.length()-1;++j){
			c[i][j+1]=ts[j];
		}
	}
	for (int i=1;i<=r;++i){
		for (int j=1;j<=s;++j){
			if (c[i][j]=='o')
			for (int k=0;k<=7;++k){
				a[i+V[k]][j+L[k]]++;
			}
		}
	}
	int sum=0,ml=0;
	for (int i=1;i<=r;++i){
		for (int j=1;j<=s;++j){
			if (c[i][j]=='o')
				sum+=a[i][j];
			else if (c[i][j]=='.') ml=max(ml,a[i][j]);
		}
	}
	sum/=2;
	sum+=ml;
	cout<<sum;
	return 0;
}