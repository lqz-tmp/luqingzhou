#include <bits/stdc++.h>
using namespace std;
int a[1005];

int main(){
	int n;
	int ans=0;
	double te;
	cin>>n;
	int j=0;
	int tmp;
	for (int i=1;i<=n;i++){
		cin>>tmp;
		if (tmp<=100&&tmp>=1){
			j++;
			a[j]=tmp;
		}
	}
	sort(a+1,a+j+1);
	for (int i=1;i<=j;i++){
		ans+=a[i];
	}
	te=ans;
	te/=j;
	cout<<setprecision(2)<<fixed<<te<<endl;
	ans=0;
	tmp=int((double)n*0.1+0.5);
	for (int i=tmp+1;i<=j-tmp;i++){
		ans+=a[i];
	}
	te=ans;
	te/=(j-2*tmp);
	te=floor(te*100.0)/100.0;
	cout<<setprecision(2)<<fixed<<te;
	return 0;
}
