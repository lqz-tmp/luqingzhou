#include <bits/stdc++.h>
using namespace std;

int b[100005],head[100005],dis[100005],Next[1000005],len[1000005],to[1000005],cnt;

typedef struct node{
	int en,cost;

	bool operator< (const node &a) const{
    	return cost>a.cost;
    }
}N;
priority_queue<node>que;

N T1,T2;

void add(int t1,int t2,int t3){
	cnt++;
	Next[cnt]=head[t1];
	head[t1]=cnt;
	to[cnt]=t2;
	len[cnt]=t3;
}

int main(){
	int n,m,t1,t2,t3;
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		head[i]=-1;
	}
	for (int i=1;i<=m;++i){
		scanf("%d %d %d",&t1,&t2,&t3);
		if (t1==t2) continue;
		add(t1,t2,t3);
		add(t2,t1,t3);
	}
	for (int i=1;i<=n;++i)
		dis[i]=1e9;
	for (int i=head[1];i!=-1;i=Next[i]){
		dis[to[i]]=min(dis[to[i]],len[i]);
		T1.en=to[i];
		T1.cost=len[i];
		que.push(T1);
	}
	while (!que.empty()){
		T2=que.top();
		que.pop();
		if (T2.cost!=dis[T2.en]) continue;
		for (int i=head[T2.en];i!=-1;i=Next[i]){
			// cout<<i<<' '<<to[i]<<endl;
			if (dis[T2.en]+len[i]<dis[to[i]]){
				dis[to[i]]=dis[T2.en]+len[i];
				T1.en=to[i];
				T1.cost=dis[to[i]];
				que.push(T1);
			}
		}
	}
	cout<<dis[n];
	return 0;
}