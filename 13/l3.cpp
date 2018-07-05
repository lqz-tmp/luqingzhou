# include <bits/stdc++.h>
using namespace std;

bool check(char a, char b){
	if ((a>='0'&&a<='9'&&b>='0'&&b<='9')||(a>='a'&&a<='z'&&b>='a'&&b<='z')){
		return true; 
	}
	return false; 
}

void cfill(char a, char b, int p1, int p2, int p3) {
	cout<<a;
	if (a<b){
		if (p1==2&&a>='a'&&a<='z'){
			a-=32;b-=32;
		}
		if (p1==3){
			cout<<setw((b-a-1)*p2)<<setfill('*')<<""; 
			return; 
		}
		if (p3==1)
			for (char c=a+1;c<b;c++) cout<<setfill(c)<<setw(p2)<<"";
		if (p3==2)
			for (char c=b-1;c>a;c--) cout<<setfill(c)<<setw(p2)<<"";
	}else cout<<'-';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int p1, p2, p3; 
	cin>>p1>>p2>>p3; 
	string s; 
	cin>>s; 
	for (int i=0;i<=(int)s.length()-1;++i){
		if (s[i+1]!='-') cout<<s[i]; 
		else if (check(s[i],s[i+2])){
			cfill(s[i],s[i+2],p1,p2,p3); 
			i += 1; 
		}else cout<<s[i]; 
	}
	return 0; 
}