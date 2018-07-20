#include <bits/stdc++.h>
using namespace std;

int b[2000000][2],mark[5005];
stack <int> st;
void print(int s){
	st.push(b[s][1]);
	if (b[s][2]!=0) print(b[s][2]);
}

int main(){
	int n,m,a[15],tq,ty,ts,cnt=1,tmp;
	bool flag=false;
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		cin>>a[i];
	}
	queue <int> q;
	queue <int> y;
	queue <int> s;
	sort(a+1,a+m+1);
	for (int i=1;i<=m;++i){
		if (a[i]==0) continue;
		q.push(a[i]);
		y.push(a[i]%n);
		s.push(cnt);
		mark[a[i]%n]=1;
		b[cnt][1]=a[i];
		b[cnt][2]=0;
		cnt++;
	}
	while (!q.empty()){
		tq=q.front();
		ty=y.front();
		ts=s.front();
		q.pop();
		y.pop();
		s.pop();
		if (ty==0){
			print(ts);
			while (!st.empty()){
				cout<<st.top();
				st.pop();
			}
			cout<<endl;
			flag=true;
			break;
		}
		for (int i=1;i<=m;++i){
			tmp=(ty*10+a[i])%n;
			if (mark[tmp]==0){
				q.push(a[i]);
				y.push(tmp);
				s.push(cnt);
				mark[tmp]=1;
				b[cnt][1]=a[i];
				b[cnt][2]=ts;
				cnt++;
			}
		}
	}
	if (!flag) cout<<0<<endl;
	return 0;
}