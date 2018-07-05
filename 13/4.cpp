#include <bits/stdc++.h>
using namespace std;

struct object
{
	int a,b;
}obj[100005];
bool cmp(object x,object y){
	return (x.b<y.b);
}
long long n,r,cn=1;
long long sum,avg,ans;
int main(){
	cin>>n>>r>>avg;
	for (int i=1;i<=n;i++){
		scanf("%d %d",&obj[i].a,&obj[i].b);
		sum+=obj[i].a;
	}
	sort(obj+1,obj+n+1,cmp);
	avg*=n;
	while (sum<avg){
		if (r-obj[cn].a>=avg-sum){
			ans+=(avg-sum)*obj[cn].b;
			sum=avg;
		}else{
			ans+=(r-obj[cn].a)*obj[cn].b;
			sum+=r-obj[cn].a;
		}
		cn++;
	}
	cout<<ans;
	return 0;
}