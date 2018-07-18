#include <bits/stdc++.h>
using namespace std;
 
int x[10],y[10];
 
int minl(int a[10]){
    int min=1000000000;
    for (int i=1;i<=8;i++){
        if (min>a[i]) min=a[i];
    }
    return min;
}
 
int main(){
    int tx=0,ty=0,lx=0,ly=0,r,t1,t2;
    cin>>r;
    for (int i=1;i<=10;i++){
        cin>>x[1];tx=0;ty=0;
        if(x[1]==-1) break;
        for (int j=2;j<=8;j++){
            cin>>x[j];
        }
        for (int j=1;j<=8;j++){
            cin>>y[j];
        }
        t1=minl(x);
        t2=minl(y);
        for (int j=1;j<=8;j++){
            if (x[j]<=r&&x[j]<t2) tx++;
        }
        for (int j=1;j<=8;j++){
            if (y[j]<=r&&y[j]<t1) ty++;
        }
        lx+=tx;
        ly+=ty;
        cout<<tx<<':'<<ty<<endl;
    }
    cout<<lx<<':'<<ly;
    return 0;
}