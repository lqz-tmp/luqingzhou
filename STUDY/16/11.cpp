#include<bits/stdc++.h>
using namespace std;

long long te;
long long a[1000005];
int main(){
    int n,t,r,l,mid,ml,ans,tmp;
    cin>>n>>t;
    for (int i=1;i<=n;++i){
    	scanf("%d",&tmp);
    	a[i]=a[i-1]+tmp;
    }
    if (a[n]<t) {
    	cout<<"Angry";
    	return 0;
    }
    ml=n;
    for (int i=1;i<=n;++i){
    	r=n+1;l=i;
    	while (l<=r){
    		mid=(l+r)/2;
    		te=a[mid]-a[i-1];
    		if (te>=t){
    			r=mid-1;
    			ans=mid;
    			ml=min(ml,ans-i+1);
    		}
    		else l=mid+1;
    	}
    }
    cout<<ml;
    return 0;
}