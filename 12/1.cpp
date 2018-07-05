#include <bits/stdc++.h>
using namespace std;

int le,co,ans;
char a[105],t1,t2,a1,a2;

int main(){
	scanf("%d\n",&le);
	for (int i=1;i<=le;i++){
		scanf("%c",&a[i]);
	}
	for (int i=1;i<=le-1;i++){
		t1=a[i];t2=a[i+1];
		co=0;
		 for (int j=i;j<=le-1;j++){
		 	if ((a[j]==t1)&&(a[j+1]==t2)) co++;
		 }
		if (co>ans){
			 ans=co;
			 a1=t1;a2=t2;
		}
	}
	printf("%c%c",a1,a2);
	return 0;
}