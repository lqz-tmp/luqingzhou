#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,ta,tb,tx,ty,i;
    long long x,y;
    cin>>x>>y>>k;
    i=0;
    while (x!=y&&i<k){
        scanf("%d %d %d %d",&ta,&tx,&tb,&ty);
        x+=ta*tx;
        y+=tb*ty;
        if (x<0) x=0;
        if (y<0) y=0;
        i++;
    }
    if (x==y)cout<<i;
    else cout<<-1;
    return 0;
}