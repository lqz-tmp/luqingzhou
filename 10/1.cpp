#include <bits/stdc++.h>
using namespace std;
int a[50005],b[50005];
 
int main(){
    int n,x,y,z;
    scanf("%d",&n);
    while (x !=-1 || y !=-1 || z !=-1){
       scanf("%d %d %d",&x,&y,&z);
       a[x]+=z;a[y+1]-=z;
    }
    b[0]=a[0];
    for (int i=1;i<n;i++){
        b[i]=b[i-1]+a[i];
    }
    int max=0;
    for (int i=0;i<n;i++) if (b[i]>max) max=b[i];
    for (int i=0;i<n;i++) if (b[i]==max) {
        printf("%d ",i);
        break;
    }
    for (int i=n;i>=0;i--) if (b[i]==max) {
        printf("%d ",i);
        break;
    }
    return 0;
}