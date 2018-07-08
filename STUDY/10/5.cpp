#include <bits/stdc++.h>
using namespace std;

struct per{
    int a;
    int b;  };

per f[5005];

bool cmp(per i,per j){
    if(i.b<j.b || ((i.a<j.a)&&(i.b==j.b)))return 1;
    else return 0;
}

int main(){
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i].b);
        f[i].a=i;
    }
    sort(f+1,f+1+n,cmp);
    for(int i=1;i<=n;i++)
        printf("%d ",f[i].a);
    printf("\n");
    long long tmp=0;
    double ans;
    for(int i=1;i<=n;i++) tmp+=f[i].b*(n-i);
    ans=tmp;
    printf("%.2f\n",ans/n);
    return 0;
}