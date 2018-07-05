
#include<bits/stdc++.h>
using namespace std;
double n,k,a[5010],sum,ans;
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>a[i],a[i]+=a[i-1];
    for(int i=k; i<=n; i++)
    for(int j=i;j<=n;j++)
        ans=max(ans,(a[j]-a[j-i])*1.0/i);
    cout<<fixed<<ans<<endl;
    return 0;
}