#include <bits/stdc++.h>
using namespace std;
  
int tmp[20],a[20][20],n,m,tans;
long long m1=10000000,m2=1;
  
bool check(int k){
    int cnt=0;
    while (k>0){
        if (k&1) cnt++;
        k>>=1;
    }
    // cout<<k<<' '<<m<<' '<<cnt<<endl;
    return (cnt==m);
}
 
bool pd(int k){
    if (tans==0) return true;
    // cout<<k<<' '<<tans<<' ';
    int w=1;
    // while (w<=k||w<=tans) w<<=1;
    while (w<=k||w<=tans){
        int t1=k&w,t2=tans&w;
        w<<=1;
        if (t1!=t2){
            // cout<<w<<' '<<t1<<' '<<t2<<' '<<(t1<t2)<<endl;
            return t1>t2;
        }
    }
    return true;
}
 
void build(int k){
    int f[20],tag[20]{0},ans=0;
    int t1=0,t2=0,t3=k,t4=0;
    while (k>0){
        t1++;
        if (k&1){
            t2++;
            tag[t2]=t1;
            if (t4==0) t4=t1;
        }
        k>>=1;
    }
    for (int i=1;i<=n;++i)
        f[i]=a[i][t4];
    f[1]=0;
    for (int i=2;i<=m;++i){
        int ml=100000005,tm=0;
        for (int j=2;j<=m;++j){
            if (f[tag[j]]!=0&&f[tag[j]]<ml){
                ml=f[tag[j]];
                tm=tag[j];
            }
        }
        ans+=ml;
          
        f[tm]=0;
        for (int j=2;j<=m;++j){
            if (f[tag[j]]!=0&&a[tm][tag[j]]<f[tag[j]]){
                f[tag[j]]=a[tm][tag[j]];
            }
        }
    }
    int sum=0;
    for (int i=1;i<=m;++i){
        sum+=tmp[tag[i]];
    }
    if (ans*m2<sum*m1||(ans*m2==sum*m1&&pd(t3))){
        m1=ans;
        m2=sum;
        tans=t3;
    }
    // cout<<"OK";
    // for (int i=1;i<=m;++i)
    //  cout<<tag[i]<<' ';
    // cout<<endl<<ans<<' '<<sum<<endl;
}
  
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        scanf("%d",&tmp[i]);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j){
            scanf("%d",&a[i][j]);
            if (a[i][j]==0) a[i][j]=100000003;
        }
    for (int i=1;i<1<<n;++i){
        if (!check(i)) continue;
        build(i);
    }
    int t1=0;
    while (tans>0){
        t1++;
        if (tans&1){
            cout<<t1<<' ';
        }
        tans>>=1;
    }
    return 0;
}