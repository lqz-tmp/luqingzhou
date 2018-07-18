#include <bits/stdc++.h>
using namespace std;

int  Next[20005];

int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int n,m,num,now,tmp;
    cin>>n>>m>>num;
    for (int i=0;i<=n;++i){
    	Next[i]=i+1;
    }
    Next[n]=1;
    int cnt=0,cn=0;
    now=0;
    while (cnt<m){
    	while (cn<num-1){
    		now=Next[now];
    		cn++;
    	}
    	tmp=Next[now];
    	Next[now]=Next[tmp];
    	now=tmp;
    	cn++;
    	printf("%d\n",now);
    	while (cn<2*num){
    		now=Next[now];
    		cn++;
    	}
    	Next[tmp]=Next[now];
    	Next[now]=tmp;
    	now=tmp;
    	cn=0;
    	cnt++;
    }
    return 0;
}