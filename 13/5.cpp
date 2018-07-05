#include <bits/stdc++.h>
using namespace std;
int a[405],ml=1,n,ai,aj;
int check(int x,int y){
	int tmp=2,i=y,j=y,t=a[y]-a[x];
	while ((i<=n)&&(a[i]-a[j]<=t)){
		if (a[i]-a[j]==t){
			tmp++;
			j=i;
		}
		i++;
	}
	return tmp;
}
int main(){
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	n =unique(a+1,a+n+1)-a-1;
	for (int i=1;i<=n-1;i++){
		for (int j=i+1;j<=n;j++){
			if (check(i,j)>ml) {ml=check(i,j);ai=i;aj=j;}
		}
	}
	cout<<ml<<endl;
	return 0;
}