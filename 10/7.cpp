#include <bits/stdc++.h>
using namespace std;

struct per{
    int l,w;
}a[1005];
bool cmp(per a,per b){
    if (a.l<b.l||(a.l==b.l&&a.w<b.w)) return true;
    return false;
}
int main(){
    int n;
    scanf("%d\n",&n);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d\n",&a[i].l,&a[i].w);
    sort(a+1,a+n+1,cmp);
    int count [1005];
    int ans=1,flag=0;
    count[1]=a[1].w;
    for (int i = 1; i <= n; ++i){
        sort(count+1,count+ans+1);
        flag=0;
        for (int j= ans; j>= 1; --j)
            if (a[i].w>=count[j]){count[j]=a[i].w;flag=1;break;}
        if (flag==0){
            ans+=1;
            count[ans]=a[i].w;
        }
    }
    printf("%d\n",ans);
    return 0;
}