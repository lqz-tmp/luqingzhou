#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
	int a[27]{0},b[100005]{0},maxn=0,te,ans=0;
	for (int i=0;i<=s.length()-1;++i){
		a[(s[i]-'a')+1]++;
	}
	for (int i=1;i<=26;++i){
		b[a[i]]++;
	}
	for (int i=1;i<=100000;i++){
		if (b[i]>maxn) {
			maxn=b[i];
			te=i;
		}
	}
	for (int i=1;i<=26;++i){
		if (a[i]!=0){
			ans+=abs(a[i]-te);
		}
	}
	if (te<=1) return "YES";
	else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}