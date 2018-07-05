#include <bits/stdc++.h>
using namespace std;

struct peo {
     int s,p,k;  //s得分 p实力 k序号
} a[200005],w[100005],l[100005];

bool cmp(peo x,peo y){
    if(x.s!=y.s) return x.s>y.s;
    else return x.k<y.k;
}

int main(){
    int n,r,q;
    scanf("%d %d %d",&n,&r,&q);
    for (int i=1;i<=2*n;i++) a[i].k=i;
    for (int i=1;i<=2*n;i++) scanf("%d",&a[i].s);
    for (int i=1;i<=2*n;i++) scanf("%d",&a[i].p);
    sort(a+1,a+2*n+1,cmp);
    for(int i=1;i<=r;i++){
        int lo=0,wi=0;
        for(int j=1;j<=2*n;j=j+2){
            if(a[j].p>a[j+1].p) w[++wi]=a[j],l[++lo]=a[j+1],w[wi].s++;
            else l[++lo]=a[j],w[++wi]=a[j+1],w[wi].s++;
        }
        merge(w+1,w+1+wi,l+1,l+1+lo,a+1,cmp);
    }
    printf("%d",a[q].k);
    return 0;
}