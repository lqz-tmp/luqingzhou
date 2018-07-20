#include <bits/stdc++.h>
using namespace std;

char c[2000005];

bool isleft(char a){
	if (a=='['||a=='('||a=='{'||a=='<')
	return true;
	else return false;
}
bool check(char b,char a){
	if ((a=='('&&b==')')||(a=='['&&b==']')||(a=='<'&&b=='>')||(a=='{'&&b=='}'))
		return true;
	else return false;
}
int main(){
	int n,len;
	bool flag;
	cin>>n;
	stack <char>s;
	for (int i=1;i<=n;++i){
		while (!s.empty()) s.pop();
		flag=true;
		scanf("%s",c+1);
		len=strlen(c+1);
		for (int j=1;j<=len;++j){
			if (s.empty()){
				if (isleft(c[j])) s.push(c[j]);
				else flag=false;
			}else{
				if (isleft(c[j])) s.push(c[j]);
				else if (check(c[j],s.top())){
					s.pop();
				}else{
					flag=false;
				}
			}
		}
		if (!s.empty()) flag=false;
		if (flag) printf("%s\n","TRUE");
		else printf("%s\n","FALSE");
	}
	return 0;
}