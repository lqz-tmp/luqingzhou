#include <bits/stdc++.h>
using namespace std;

int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int Next[1005],Pre[1005],k,n,m;
    cin>>k>>m>>n;
    for (int i=0;i<=k;++i){
    	Next[i]=i+1;
    }
    for (int i=k;i>=0;--i){
    	Pre[i]=i-1;
    }
    Pre[1]=k;
    Next[k]=1;
    int now=0,tmp,cn;
    bool flag=true;
    while(k>5){
    	cn=1;
    	k--;
    	if (flag){
    		while (cn<m){
    			cn++;
    			now=Next[now];
    		}
	    	tmp=Next[now];
	    	Next[now]=Next[tmp];
	    	tmp=Next[tmp];
	    	Pre[tmp]=now;
	    	now=Next[now];
    	}else{
    		while (cn<n){
    			cn++;
    			now=Pre[now];
    		}
    		tmp=Pre[now];
    		Pre[now]=Pre[tmp];
    		tmp=Pre[tmp];
    		Next[tmp]=now;
    		now=Pre[now];
    	}
    	flag=!flag;
    }

    tmp=now;
    for (int i=1;i<=5;++i){
    	tmp=max(tmp,now);
    	now=Next[now];
    }
    now=tmp;
    cout<<now;
    for (int i=1;i<=4;++i){
    	now=Pre[now];
    	cout<<' '<<now;
    }
    return 0;
}