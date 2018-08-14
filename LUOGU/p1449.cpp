#include <bits/stdc++.h>
using namespace std;

int main(){
	int sum=0,tmp=0;
	char s[10005];
	scanf("%s",s+1);
	stack <int> a;
	for (int i=1;i<=strlen(s+1);++i){
		if (s[i]=='@') break;
		if (s[i]=='.') a.push(tmp),tmp=0;
		else if (s[i]>='0'&&s[i]<='9') tmp=tmp*10+(s[i]-'0');
		else if (s[i]=='+'){
			int t1,t2;
			t2=a.top();
			a.pop();
			t1=a.top();
			a.pop();
			sum=t1+t2;
			a.push(sum);
			tmp=0;
		}
		else if (s[i]=='-'){
			int t1,t2;
			t2=a.top();
			a.pop();
			t1=a.top();
			a.pop();
			sum=t1-t2;
			a.push(sum);
			tmp=0;
		}
		else if (s[i]=='*'){
			int t1,t2;
			t2=a.top();
			a.pop();
			t1=a.top();
			a.pop();
			sum=t1*t2;
			a.push(sum);
			tmp=0;
		}
		else if (s[i]=='/'){
			int t1,t2;
			t2=a.top();
			a.pop();
			t1=a.top();
			a.pop();
			sum=t1/t2;
			a.push(sum);
			tmp=0;
		}
	}
	printf("%d",a.top());
	return 0;
}