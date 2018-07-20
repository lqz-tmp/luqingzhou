#include <bits/stdc++.h>
using namespace std;

int main(){
	int tmp,t,n;
	stack <int>s;
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&tmp);
		if (tmp==1){
			scanf("%d",&t);
			s.push(t);
		}else if(tmp==2){
			s.pop();
		}else{
			printf("%d\n",s.top());
		}
	}
	cout<<s.size();
	return 0;
}