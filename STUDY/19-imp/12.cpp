#include <bits/stdc++.h>
using namespace std;

int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int n,tmp,pre,te=1,ans=0;
    cin>>n;
    cin>>pre;
    for (int i=1;i<=n-1;++i){
    	scanf("%d",&tmp);
    	if (tmp>pre){
    	te++;
    	pre=tmp;
    	}
    	else{
    		ans=max(ans,te);
    		te=1;
    		pre=tmp;
    	}
    }
    ans=max(ans,te);
    cout<<ans;
    return 0;
}