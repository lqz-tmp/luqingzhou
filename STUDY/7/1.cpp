#include <cstdio>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	map<string,int> a;
	int n;
	scanf("%d\n",n);
	string b[n];
	for (int i=0;i<n;i++){
		getline(b[i]);
		sort(b[i].begin(),b[i].end());
		a[b[i]]+=1;
		puts(a[b[i]]-1);
		putchar("\n");
	}
	return 0;
}