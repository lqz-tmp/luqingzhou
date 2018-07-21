#include <bits/stdc++.h>
using namespace std;

int a[1000005],f[1000005],n,m,top,pos;

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
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;++i){
        if (a[i]*2>=m){
            if(a[i]*2>=f[top]){
                top++;
                f[top]=a[i]*2;
            }else{
                pos=search(1,top,a[i]*2);
                if(f[pos]>a[i]*2) f[pos]=a[i]*2;
            }
        }
        if (a[i]>=m){
            if(a[i]>=f[top]){
                top++;
                f[top]=a[i];
            }else{
                pos=search(1,top,a[i]);
                if(f[pos]>a[i]) f[pos]=a[i];
            }
        }
    }
    cout<<top<<endl;
    return 0;
}