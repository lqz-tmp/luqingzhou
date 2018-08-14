#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1073741824")
using namespace std;

int head[400005],Next[400005],a[400005],mark[400005],tmp[400005],cnt,tans,ccc;
 
void add(int st,int en){
    cnt++;
    Next[cnt]=head[st];
    head[st]=cnt;
    a[cnt]=en;
}
 
void bl(int st,int on,int step){
	// cout<<st<<endl;
	ccc++;
	if (ccc>10000000) return;
    for (int i=head[st];i!=-1;i=Next[i]){
    	if (a[i]==on) continue;
        bl(a[i],st,step+1);
    }
    mark[st]++;
}

int find(int n){
	for (int i=0;i<=n;++i) tmp[i]=0;
	for (int i=1;i<=cnt;++i){
		tmp[a[i]]++;
	}
	int ml=0,ans;
	for (int i=0;i<=n;++i){
		if (tmp[i]>ml){
			ml=tmp[i];
			ans=i;
		}
	}
	tans=tmp[ans];
	// cout<<tmp[ans]<<endl;
	return ans;
}

int main(){
	int t,m,n,k;
	cin>>t;
	for (int o=1;o<=t;o++){
		tans=0;
		cin>>n>>m>>k;
		cnt=0;
		for (int i=1;i<=400000;++i){
			mark[i]=Next[i]=a[i]=0;
			head[i]=-1;
		}
		for (int i=1;i<=m;++i){
			int t1,t2;
			scanf("%d %d",&t1,&t2);
			add(t1,t2);
			add(t2,t1);
		}
		int start=find(n);
		bl(start,start,0);
		// cout<<"OK";
		for (int i=head[start];i!=-1;i=Next[i]){
        	mark[i]=-1;
    	}
    	mark[start]=-1;
    	for (int i=0;i<=n-1;++i){
    		if (mark[i]==0) tans++,mark[i]=1e9;
    		else if (mark[i]==-1) mark[i]=1e9;
    	}
    	sort(mark,mark+n);
    	int cjt=1;
    	while (k>mark[cjt]&&mark[cjt]!=1e9){
    		k-=mark[cjt];
    		cjt++;
    	}
    	tans+=cjt-1;
    	cout<<tans<<endl;
	}
    return 0;
}