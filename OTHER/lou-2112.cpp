#include <bits/stdc++.h>
using namespace std;

int n,tmp[10],st[3]={10,1,-1};

int lo(int a){
	int ans=0;
	while (a>0){
		ans++;
		a/=10;
	}
	return ans+1;
}

bool check(){
	int ans=0,te=0;
	for (int i=n;i>=1;--i){
		if (tmp[i]!=10) {
			if (te==0)
				ans+=i*tmp[i];
			else ans+=(i*10+te)*tmp[i];
			te=0;
		}else{
			if (te==0) te=i;
			else te=i*pow(10,lo(te))+te;
		}
	}
	// cout<<"ANS="<<ans<<endl;
	return (ans==0);
}

void print(){
	printf("%d",1);;
	for (int i=2;i<=n;++i){
		if (tmp[i]==1) printf("%c",'+');
		else if (tmp[i]==-1) printf("%c",'-');
		else printf("%c",' ');
		printf("%d",i);
	}
	printf("\n");
}

void dfs(int step){
	if (step>n){
		if (check()) 
			print();
		return;
	}
	for (int i=0;i<3;++i){
		tmp[step]=st[i];
		dfs(step+1);
	}
}

int main(){
	cin>>n;
	tmp[1]=1;
	dfs(2);
	return 0;
}