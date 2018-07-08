#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1001],n,d[1001],c[1001];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
       scanf("%d",&a[i]);
    }
    memcpy(c,a,sizeof(c));
    sort(c+1,c+1+n);
    int k=0;
    for(int i=1;i<=n;i++){
      if(a[i]!=c[i]){
        int t=0;
        for(int j=n;j>=i+1;j--){
          if(a[j]==c[i]&&c[i]!=c[j]){
           t=j;
           if(a[i]==c[j]) break;
          }
        }
        swap(a[i],a[t]);
        k++;
      }
    }
    printf("%d",k);
    return 0;
}