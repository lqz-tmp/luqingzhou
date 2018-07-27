#include <bits/stdc++.h>
using namespace std;

int n,m,a[10005],total,flag;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	cin>>n>>m;
	for (int i=n;i>=1;--i){
		scanf("%d",&a[i]);
	}
	total=2;
	while (m>0){
		flag=0;
		for (int i=1;i<total;i++){
			if (a[i]>a[total]){
				swap(a[i],a[total]);
				sort(a+1,a+total,cmp);
				total=2;
				flag=1;
				m--;
				break;
			}

		}
		if (flag==0){
			total++;
		}
	}
	for (int i=n;i>=1;--i){
		printf("%d ",a[i]);
	}
	return 0;
}