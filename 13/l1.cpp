#include <bits/stdc++.h>
using namespace std;
struct per
{
	int a,b;
}arr[100005];
bool cmp(per x,per y){
	return(x.a<y.a);
}
int main(){
	int want,cb,n=2;
	cin>>want>>cb>>arr[1].b;
	arr[1].a=cb;
	scanf("%d",&arr[n].a);
	scanf("%d",&arr[n].b);
	n++;
	while((arr[n-1].a!=-1)&&(arr[n-1].b!=-1)){
		scanf("%d",&arr[n].a);
		scanf("%d",&arr[n].b);
		n++;
	}
	n-=2;
	sort(arr+1,arr+n+1,cmp);
	int x[100005]{0};
	int j=1;
	x[cb]=arr[1].b;
	for (int i=cb+1;i<=arr[n].a;i++){
		if (i>arr[j].a) j++;
		x[i]=x[i-1]+(arr[j+1].b-arr[j].b)/(arr[j+1].a-arr[j].a);
	}
	int ans=1000000000,maxl;
	for (int i=cb;i<=arr[n].a;i++){
		if (((i-cb)*x[i]==maxl)&&(abs(i)<abs(ans))){
			ans=i;
		}else if((i-cb)*x[i]>maxl){
			maxl=(i-cb)*x[i];
			ans=i;
		}
	}
	ans=want-ans;
	cout<<ans;
	return 0;
}