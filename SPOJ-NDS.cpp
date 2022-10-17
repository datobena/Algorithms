
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define pb push_back


int lis(int a[], int n, int l) {
  if(l>n) return -1;
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (l >= j && d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }
    return d[l] < INF ? d[l] : -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
      scanf("%d ", arr + i);
    }
    int l;
    scanf("%d", &l);
    printf("%d\n", lis(arr, n, l));
  }
  return 0;
}
