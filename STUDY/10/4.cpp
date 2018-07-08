#include <bits/stdc++.h>
using namespace std;
string a[20];
bool cmp(string s1, string s2) {  
    return s1 + s2 > s2 + s1;  
}  
int main() {
    int n;
    scanf("%d\n",&n);
    char tmp[100];
    for (int i = 1; i <= n; ++i){
        scanf("%s", tmp);
        a[i]=(tmp);
    }
    sort(a+1,a+n+1,cmp);
    for (int i = 1; i <= n; ++i)
        printf("%s" , a[i].c_str());
    return 0;
}