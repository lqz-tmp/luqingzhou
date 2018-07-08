#include <bits/stdc++.h>
using namespace std;
int a[100005],tmp,ans,n;
bool ch(){
	for (int i=1;i<=n;i++){
		if (a[i]!=0) return true;
	}
	return false;
}
bool cmp(int a,int b){
	if ((a<b)||(a==0)) return true;
	return false;
}
int fi(){
	int tmp=1,max=0,ans=0,te=0;
	for (int i=1;i<=n;i++){
		if(a[i]!=0){
			te=i;
			break;
		}
	}
	for (int i=te;i<=n;i++){
		if (a[i-1]==a[i]) {
			tmp++;
		}else{
			if (tmp>=max){
				max=tmp;
				ans=a[i-1];
			}
			tmp=1;
		}
	}
	if (tmp>max){
	max=tmp;
	ans=a[n];
    }
    if (ans==0) ans=a[n];
	return ans;
}
void ma(int m){
	for (int i=1;i<=n;i++){
		if (a[i]!=0) a[i]-=m;
	}
	sort(a+1,a+n+1,cmp);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	 while (ch()) {
		ans++;
		tmp=fi();
		ma(tmp);
	}
	cout<<ans<<endl;
}