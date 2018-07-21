#include <bits/stdc++.h>
using namespace std;

struct per
{
	int x,y;
}a[100005];

bool cmp(per a,per b){
	return (a.y<b.y);
}

int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int n;
    long long t;
    cin>>n>>t;
    for (int i=1;i<=n;++i){
    	scanf("%d",&a[i].x);
    }
    for (int i=1;i<=n;++i){
    	scanf("%d",&a[i].y);
    }
    sort(a+1,a+n+1,cmp);
    int cn=0,ans=0;
    while (t>0&&cn<=n){
    	if (t<a[cn].y) break;
    	else if (t<a[cn].y*a[cn].x){
    		ans+=t/a[cn].y;
    		t%=a[cn].y;
    	}
    	else {
    		ans+=a[cn].x;
    		t-=a[cn].y*a[cn].x;
    		cn++;
    	}
    }
    cout<<ans<<endl;
    return 0;
}