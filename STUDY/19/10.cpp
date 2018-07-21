#include <bits/stdc++.h>
using namespace std;

long long n,m,k,ans;

long long add(long long mid){
	long long sum=0;
	sum+=mid;
	if (k<=mid){
		sum+=(mid*2-k)*(k-1)/2;
	}else{
		sum+=(mid-1)*mid/2;
		sum+=k-mid;
	}
	if (n-k<=mid-1){
		sum+=(mid*2-n+k-1)*(n-k)/2;
	}else{
		sum+=(mid-1)*mid/2;
		sum+=n-k-mid+1;
	}
	return sum;
}

int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    cin>>n>>m>>k;
    long long l=1,r=m,mid;
    long long sum;
    while (l<=r){
    	mid=(l+r)/2;
    	sum=add(mid);
    	if (sum<=m){
    		ans=mid;
    		l=mid+1;
    	}else{
    		r=mid-1;
    	}
    }
    cout<<ans<<endl;
    return 0;
}