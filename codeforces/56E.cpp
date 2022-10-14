#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define pb push_back
#define pp pair<int, pair<int, int>>

bool makesFall(pp left, pp right){
  int xleft = left.first, hleft = left.second.first;
  int xright = right.first;
  return xright >= xleft + 1 && xright <= xleft + hleft - 1;
}
int main(){
  int n;
  scanf("%d", &n);
  pp arr[n];
  int breakPoint[n];
  int dp[n];
  int ans[n];
  fill_n(breakPoint, n, -1);
  fill_n(dp, n, 1);

  for(int i = 0; i < n; i++){
    int x, h;
    scanf("%d %d", &x, &h);
    arr[i] = make_pair(x,make_pair(h,i));
  }
  sort(arr, arr+n);
  for(int i = n -2; i >= 0; i--){
    int next = i + 1;
    while(next != -1 && makesFall(arr[i], arr[next])){
      dp[i] += dp[next];
      next = breakPoint[next];
    }
    breakPoint[i] = next;
  }
  for(int i = 0; i < n ; i++){
    pp cur = arr[i];
    ans[cur.second.second] = dp[i];
  }
  for(int i = 0; i < n-1; i++)
    printf("%d ", ans[i]);
  printf("%d\n", ans[n - 1]);
  return 0;
}
