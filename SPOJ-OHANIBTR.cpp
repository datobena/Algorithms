#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define pb push_back

int lis(vector<pair<int, int>> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i].first) - d.begin();
        if (d[j-1] < a[i].first && a[i].first < d[j])
            d[j] = a[i].first;
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

void makeTree(int ans2[], vector<pair<int, int>> &vec, int len, int i, int l = 0){
  if(len == 0) return;
  int k = sizeof(int)*8 - __builtin_clz((unsigned int)len);
  int left, idx;
  if(len+1 == 1<<k){
    left = len>>1;
    idx = left + l;
    ans2[idx] = (i == -1) ? -1 : vec[i].first;
  }
  else{
    left = min(1<<(k-2), len - (1<<(k-1)) + 1) + ((1<<(k-1)) - 1)/2;
    idx = left + l;
    ans2[idx] = (i == -1) ? -1 : vec[i].first;
  }
    makeTree(ans2, vec, left, idx, l);
    makeTree(ans2, vec, len - left - 1, idx, idx + 1);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  scanf("%d", &t);
  for(int idx = 1; idx <= t; idx++){
    int n;
    scanf("%d", &n);
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++){
      int cur;
      scanf("%d", &cur);
      arr[i] = make_pair(cur, i);
    }
    int ans1 = n - lis(arr);
    sort(arr.begin(), arr.end());
    int ans2[n];
    makeTree(ans2, arr, n, -1);
    printf("Case %d:\n", idx);
    printf("Minimum Move: %d\n", ans1);
    for(int i = 0; i < n - 1; i++){
      printf("%d ", ans2[i]);
    }
    printf("%d\n", ans2[n-1]);
  }
  return 0;
}
