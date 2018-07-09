#include <bits/stdc++.h>
using namespace std;

struct per{
	int x,y;
}a[55];

int fr[55],fc[55],n,r,c,ans=1000;

void sov1(){
	int cn=0,sum=0,cnt=0;
	bool flag=false;
	for (int i=1;i<=n;++i){
		if (a[i].y>r) {
			cn++;
			fr[cn]=a[i].x;
		}else if (a[i].x>r){
			cn++;
			fr[cn]=a[i].y;
		}
	}
	sort(fr+1,fr+cn+1);
	for (int i=cn;i>=1;--i){
		sum+=fr[i];
		cnt++;
		if (sum>=c){
			flag=true;
			break;
		}
	}
	if (flag){
		ans=min(ans,cnt);
	}
	return;
}

void sov2(){
	int cn=0,sum=0,cnt=0;
	bool flag=false;
	for (int i=1;i<=n;++i){
		if (a[i].y>c) {
			cn++;
			fc[cn]=a[i].x;
		}else if (a[i].x>c){
			cn++;
			fc[cn]=a[i].y;
		}
	}
	sort(fc+1,fc+cn+1);
	for (int i=cn;i>=1;--i){
		sum+=fc[i];
		cnt++;
		if (sum>=r){
			flag=true;
			break;
		}
	}
	if (flag){
		ans=min(ans,cnt);
	}
	return;
}

int main(){
	cin>>r>>c>>n;
	for (int i=1;i<=n;++i){
		scanf("%d %d",&a[i].x,&a[i].y);
		if (a[i].x<a[i].y) swap(a[i].x,a[i].y);
	}
	sov1();
	sov2();
	if (ans==1000){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans;
	return 0;
}