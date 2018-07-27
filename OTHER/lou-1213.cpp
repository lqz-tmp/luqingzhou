#include <bits/stdc++.h>
using namespace std;

bool IsPrime[1000010];
int Prim[1000010];
void  checkPrime(int n){
    int num = 0, j;
    for(int i = 2; i <= n; i ++){
        if(!IsPrime[i])
            Prim[num ++] = i;
        for(j  = 0; j < num; j ++){
            if(i * Prim[j] > n)
                break;
            IsPrime[i * Prim[j]] = true;
            if(i % Prim[j] == 0)
                break;   //i的因子已经扫过了，直接退出循环
        }
    }
}

bool checkhw(int n){
	int a[15],cnt=0;
	while (n!=0){
		cnt++;
		a[cnt]=n%10;
		n/=10;
	}
	for (int i=1;i<=cnt/2;++i){
		if (a[i]!=a[cnt-i+1]) return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	checkPrime(n);
	for (int i=11;i<=n;++i){
		if (!IsPrime[i]&&checkhw(i)) printf("%d\n",i);
	}
	return 0;
}