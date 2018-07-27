#include <bits/stdc++.h>
using namespace std;

int n,a[40005],tmp[40005];
long long ans;

void ms(int l,int r){
	if (l==r) return;
	int k=(l+r)/2;
	ms(l,k);
	ms(k+1,r);
	int tl=l,tr=k+1,po=l;
	while (tl<=k&&tr<=r){
		if (a[tl]<=a[tr]){
			tmp[po]=a[tl];
			tl++;
			po++;
		}else{
			tmp[po]=a[tr];
			tr++;
			po++;
			ans+=k-tl+1;
		}
	}
	while (tl<=k){
		tmp[po]=a[tl];
		po++;
		tl++;
	}
	while (tr<=r){
		tmp[po]=a[tr];
		po++;
		tr++;
	}
	for (int x=l;x<=r;++x){
		a[x]=tmp[x];
	}
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	ms(1,n);
	cout<<ans<<endl;
}