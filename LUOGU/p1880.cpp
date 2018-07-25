#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[105],f[305][305],g[305][305],tmp;

int cost(int x,int y){
	return a[y]-a[x-1];
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=n;++i) a[i+n]=a[i];
	for (int i=1;i<=2*n;++i) a[i]+=a[i-1];
	for (int len=2;len<=n;len++){
		for (int i=1,tmp=i+len-1;i<n+n&&tmp<n+n;++i,tmp=i+len-1){
			g[i][tmp]=1e9;
			for (int k=i;k<=tmp-1;++k){
				f[i][tmp]=max(f[i][k]+f[k+1][tmp]+cost(i,tmp),f[i][tmp]);
				g[i][tmp]=min(g[i][k]+g[k+1][tmp]+cost(i,tmp),g[i][tmp]);
			}
		}
	}
    int minl=1e9;
    int maxl=0;  
    for(int i=1;i<=n;i++)  
    {  
        maxl=max(maxl,f[i][i+n-1]);  
        minl=min(minl,g[i][i+n-1]);  
    }  
    printf("%d\n%d",minl,maxl);  
	return 0;
}