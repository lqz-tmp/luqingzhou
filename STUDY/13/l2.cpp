#include <bits/stdc++.h>
using namespace std;
int n,m,timel,mp[21][21],ans = 0;
inline void dfs(int nowtime,int x,int y) {
  int mx,my,Max = -99999;
  for (int i = 1;i <= n;i++)
    for (int j = 1;j <= m;j++)
      if (mp[i][j] > Max) {
        Max = mp[i][j];
        mx = i;
        my = j;
      }
  if (!y) y = my;
  if (nowtime < abs(x-mx)+abs(y-my)+mx+1 || !mp[mx][my])
    return;
  else {
    ans += mp[mx][my];
    mp[mx][my] = 0;
    dfs(nowtime-abs(x-mx)-abs(y-my)-1,mx,my);
  }
}
int main() {
  ios :: sync_with_stdio(false);
  cin >> n >> m >> timel;
  for (int i = 1;i <= n;i++)
    for (int j = 1;j <= m;j++) cin >> mp[i][j];
  dfs(timel,0,0);
  cout << ans;
  return 0;
}