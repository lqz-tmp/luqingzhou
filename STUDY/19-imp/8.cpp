#include <bits/stdc++.h>
using namespace std;

int main() 
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    char c[100005];
    scanf("%s",c+1);
    int low=0,up=0,tl=0,tu=0,ans=999999999;
    int len=strlen(c+1);
    for (int i=1;i<=len;++i){
    	if (c[i]>='a'&&c[i]<='z') low++;
    	else if (c[i]>='A'&&c[i]<='Z') up++;
    }
    for (int i=0;i<=len;++i){
    	if (c[i]>='a'&&c[i]<='z') tl++;
    	else if (c[i]>='A'&&c[i]<='Z') tu++;
    	ans=min(ans,tl+up-tu);
    }
    cout<<ans;
    return 0;
}

// using namespace std;

// int n, a[100001], d[100001][2];
// string s;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin >> s;
//     n = s.length();
//     for (int i = 0; i < n; i++)
//         if (s[i] >= 97) a[i] = 1;
//     if (a[0]) d[0][0] = 1;
//     else d[0][1] = 1;
//     for (int i = 1; i < n; i++)
//         if (a[i]) {
//             d[i][1] = min(d[i - 1][1], d[i - 1][0]);
//             d[i][0] = d[i - 1][0] + 1;
//         }
//         else {
//             d[i][0] = d[i - 1][0];
//             d[i][1] = min(d[i - 1][0], d[i - 1][1]) + 1;
//         }
//     cout << min(d[n - 1][0], d[n - 1][1]) << endl;

//     return 0;
// }