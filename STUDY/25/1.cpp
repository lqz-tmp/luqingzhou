#include <bits/stdc++.h>
using namespace std;

int yy1,m1,d1,y,m,d,fy,fm,fd,month[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};

int checky(int y){
	return ((y%4==0&&y%100!=0)||y%400==0);
}

int checkm(int y,int m){
	int ans=month[m];
	if (m==2&&checky(y)==1) ans++;
	return ans;
}

int to1(int y,int m,int d){
	int ans=0;
	for (int i=1;i<=y-1;++i)
		ans+=365+checky(i);
	for (int i=1;i<=m-1;++i)
		ans+=checkm(y,i);
	ans+=d-1;
	return ans;
}

int main(){
	cin>>yy1>>m1>>d1>>y>>m>>d;
	if (m1!=2||d1!=29) yy1+=19; 
	else yy1+=76;
	int ans1=to1(yy1,m1,d1);
	int ans2=to1(y,m,d);
	cout<<ans1-ans2<<endl;
	return 0;
}