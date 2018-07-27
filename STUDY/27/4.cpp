#include <bits/stdc++.h>
using namespace std;
 
int a[100005],tree[400005],tmp[100005],t2[100005],n,m,x,y,z;
 
void build(int le,int ri,int m){
    if (le==ri){
        tree[m]=a[le];
        return ;
    }
    int mid=(le+ri)/2;
    build(le,mid,m*2);
    build(mid+1,ri,m*2+1);
    tree[m]=tree[m*2]+tree[m*2+1];
}
 
int get(int le,int ri,int m,int n){
    if (le==ri){
        tree[m]=0;
        return le;
    }
    int mid=(le+ri)/2,re;
    if (n<=tree[m*2]) re=get(le,mid,m*2,n);
    else re=get(mid+1,ri,m*2+1,n-tree[m*2]);
    tree[m]=tree[m*2]+tree[m*2+1];
    return re;
}
 
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        a[i]=1;
    }
    build(1,n,1);
    for (int i=2;i<=n;++i){
        scanf("%d",&tmp[i]);
    }
    a[1]=0;
    for (int i=n;i>=1;--i)
        t2[i]=get(1,n,1,tmp[i]+1);
    for (int i=1;i<=n;++i)
        printf("%d\n",t2[i]);
    return 0;
}