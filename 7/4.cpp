#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n,tmp;
	scanf("%d\n",&n);
	int a[100001];
	memset(a,0,sizeof(a));
	for (int i=0;i<n;i++){
		 scanf("%d",&tmp);
		a[tmp]++;
	}
	int max=0;
	for (int i=0;i<100001;i++){
		if (a[i]>max) max=a[i];
	}
	for (int i=0;i<100001;i++){
		if (a[i]==max) printf("%d  %d\n",i,max);
	}
	return 0;
}