#include <bits/stdc++.h>
using namespace std;

int a[105],n;

int search(int x,int y){
    int top=0,pos,f[105]={0};
    for (int i=x;i<=y;++i){
        if(a[i]>f[top]){
            top++;
            f[top]=a[i];
        }else{
            pos=lower_bound(f,f+top,a[i])-f;
            f[pos]=a[i];
        }
    }
    return top;
}

int search1(int x,int y){
    int top=0,pos,f[105]={0};
    for (int i=x;i>=y;--i){
        if(a[i]>f[top]){
            top++;
            f[top]=a[i];
        }else{
            pos=lower_bound(f,f+top,a[i])-f;
            f[pos]=a[i];
        }
    }
    return top;
}


int peo(int s){
    int a1,a2;
    a1=search(1,s);
    a2=search1(n,s);
    return a1+a2-1;
}

int main(){
    int ans=0,tmp;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        tmp=peo(i);
        ans=max(ans,tmp);
    }
    ans=n-ans;
    cout<<ans<<endl;
    return 0;
}