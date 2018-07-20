#include <bits/stdc++.h>
using namespace std;

int a[100005],f[100005],n,top,pos;

int search(int a,int b,int s){
	int ans,l=a,r=b,mid;
	while (l<=r) {
		mid=(l+r)/2;
		if (f[mid]>=s){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        a[i]-=i;
    }
    for (int i=1;i<=n;++i){
        if(a[i]>=f[top]){
            top++;
            f[top]=a[i];
        }else{
            pos=search(1,top,a[i]);
            if(f[pos]>a[i]) f[pos]=a[i];
        }
    }
    cout<<n-top<<endl;
    return 0;
}