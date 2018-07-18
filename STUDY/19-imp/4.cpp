#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    char c[10005];
    scanf("%s",c+1);
    while (c[1]!='0'){
    	int len=strlen(c+1);
    	for (int i=len;i>=1;--i){
    		a[i]+=c[len-i+1]-'0';
    	}
    	scanf("%s",c+1);
    }
    for (int i=1;i<=1000003;++i){
    	if (a[i]>=10){
    		a[i+1]+=a[i]/10;
    		a[i]%=10;
    	}
    }
    bool flag=false;
    for (int i=1000003;i>=1;--i){
    	if (a[i]!=0) flag=true;
    	if (flag) printf("%d",a[i]);
    }
    return 0;
}