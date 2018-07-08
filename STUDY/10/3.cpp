# include <bits/stdc++.h>
using namespace std;

struct per{
	int d,s,t;
}b[1000005];
int a[1000005],sum[1000005],tmp[1000005],m,n;
bool pd(int p){
	memset(tmp,0,sizeof(tmp));
	for (int i = 1; i <=p; ++i){
		tmp[b[i].s]+=b[i].d;
		tmp[b[i].t+1]-=b[i].d;
	}
	for (int i = 1; i <=n; ++i){
		tmp[i]=tmp[i-1]+tmp[i];
		if (tmp[i]>a[i]) return false;
	}
	return true;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
	}
	for (int i = 1; i <= m; ++i){
		scanf("%d %d %d",&b[i].d,&b[i].s,&b[i].t);
	}
	int ans=0;
	int l=1,r=m,mid;
	while (l<=r){
        mid=(l+r) / 2;
        if (pd(mid)) l=mid+1;
         else {r=mid-1; ans=mid;}
     }
     if (ans==0) printf("0");
     else printf("-1\n%d",ans);
	return 0;
}