#include <bits/stdc++.h>
using namespace std;

struct per{
	int x,y;
}a[55],b[55];


bool cmp(per m,per n){
	return (m.x>n.x||(m.x==n.x&&m.y>n.y));
}


int main(){
	int n,r,c,ans=1000,cnt=0;
	cin>>r>>c>>n;
	long long sum;
	for (int i=1;i<=n;++i){
		scanf("%d %d",&a[i].x,&a[i].y);
		b[i].x=a[i].x;
		b[i].y=a[i].y;
	}

	for (int i=1;i<=n;++i){
		if (a[i].x>r&&a[i].y>r&&a[i].x>a[i].y) swap(a[i].x,a[i].y);
		else if (a[i].x<r&&a[i].y<r) a[i].x=a[i].y=0;
		else if (a[i].x<=a[i].y&&a[i].y>r&&a[i].x<r) swap(a[i].x,a[i].y);

		// cout<<a[i].x<<' '<<a[i].y<<endl;
	}

	sort(a+1,a+n+1,cmp);
	// for (int i=1;i<=n;++i){
	// 	cout<<a[i].x<<' '<<a[i].y<<endl;
	// }
	bool flag;
	flag=false;
	sum=0; cnt=0;
	for (int i=1;i<=n;++i){
		if (a[i].x>r) {
			sum+=a[i].y;
			cnt++;
		}
		else break;
		if (sum>=c){
			flag=true;
			break;
		}
		// cout<<a[i].x<<' '<<a[i].y<<endl;
	}
	if (flag) ans=min(ans,cnt);


	for (int i=1;i<=n;++i){
		if (b[i].x>c&&b[i].y>c&&b[i].x>b[i].y) swap(b[i].x,b[i].y);
		else if (b[i].x<c&&b[i].y<c) b[i].x=b[i].y=0;
		else if (b[i].x<=b[i].y&&b[i].y>c&&b[i].x<c) swap(b[i].x,b[i].y);
	}

	sort(b+1,b+n+1,cmp);
	flag=false;
	sum=0; cnt=0;
	for (int i=1;i<=n;++i){
		if (b[i].x>c) {
			sum+=b[i].y;
			cnt++;
		}
		else break;
		if (sum>=c){
			flag=true;
			break;
		}
	}
	if (flag) ans=min(ans,cnt);

	if (ans==1000){ 
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans;
	return 0;
}