#include <bits/stdc++.h>
using namespace std;
int a[100005],n,ml,tmp,ans,flag=1;
int check(int i){
	int ans=0;
	while (i>1){
		i/=2;
		ans++;
	}
		return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
    ml=1;ans=0;
    while (ml*2<=a[n]) ml*=2;
    int tmp=ml*2-1;
    while ((ml>0)&&(flag==1)) {
        int temp=tmp;
        for (int i=1;i<=n;++i) {
            if ((a[i]&ml)!=0) {
                temp&=a[i];
                ans++;
            }
        }
        if ((temp&(ml-1))==0) {
        	cout<<check(ml)<<'\n'<<ans;
        	flag=0;
        }
        ans=0;
        ml/=2;
    }
    return 0;
}