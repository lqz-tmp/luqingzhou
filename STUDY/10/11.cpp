#include<bits/stdc++.h>  
using namespace std;  
int n,m,w[1005];  
long long ans=0;  
int main()  
{  
    scanf("%d%d",&n,&m);  
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);  
    for(int i=1;i<=m;i++)  
    {  
        int x,y;  
        scanf("%d %d",&x,&y);  
        ans+=min(w[x],w[y]);  
    }  
    cout<<ans<<endl;  
    return 0;  
}  