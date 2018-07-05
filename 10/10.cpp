#include <bits/stdc++.h>
using namespace std;
char a[15][15], b[15][15], c[15][15];
char tmp[15][15];
int n;

inline bool pd() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (tmp[i][j] != b[i][j])
                return false;
    return true;
}

bool zw1(char a[][15]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[j][n-1-i] = a[i][j];
    return pd();
}

bool zw2(char a[][15]) {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            tmp[n-1-i][n-1-j] = a[i][j];
    return pd();
}

bool zw3(char a[][15]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[n-1-j][i] = a[i][j];
    return pd();
}

bool zw4(char a[][15], char tmp[][15]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][n-1-j] = a[i][j];
    return pd();
}

bool zw5() {
    zw4(a, c);
    if (zw1(c) || zw2(c) || zw3(c))
        return true;
    else 
        return false;
}

bool zw6() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = a[i][j];
    return pd();
}

int main() {
    scanf("%d\n",&n);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin>>a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>b[i][j];
    int ans=0;
    if (zw6()) ans=6;
    if (zw5()) ans=5;
    if (zw4(a,tmp)) ans=4;
    if (zw3(a)) ans=3;
    if (zw2(a)) ans=2;
    if (zw1(a)) ans=1;
    if (ans==0) ans=7;
    printf("%d",ans);
    return 0;
}