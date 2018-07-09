#include <bits/stdc++.h>
using namespace std;

int a[500005],tmp[500005];
long long ans=0;

void ms(int l,int r){
	int mid;
	if (l==r) return;
	mid=(l+r)/2;
	ms(l,mid);
	ms(mid+1,r);
	int i=l,j=mid+1,k=l;
	while (i<=mid && j<=r){
		if (a[i]<=a[j]){
			tmp[k]=a[i];
			k++;
			i++;
		}else{
			tmp[k]=a[j];
			ans+=mid-i+1;
			k++;
			j++;
		}
	}
	while (i<=mid){
		tmp[k]=a[i];
		k++;
		i++;
	}
	while (j<=r){
		tmp[k]=a[j];
		k++;
		j++;
	}
	for (int i=l;i<=r;++i){
		a[i]=tmp[i];
	}
}

int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	ms(1,n);
	cout<<ans;
	return 0;
}