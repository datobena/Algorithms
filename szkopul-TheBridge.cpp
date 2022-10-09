//Link to the problem: https://szkopul.edu.pl/problemset/problem/QOI_596ZIIk4CbamVRXVvbAI/site/?key=statement
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define pb push_back
#define ll long long

int arr[100003];
int main(){
  int n, ans2 = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int t;
    scanf("%d", &t);
    arr[i] = t;
  }
  sort(arr, arr + n);
  int ans = 0;
  for(int i = n - 1; i >= 0;){
  // case when its only one!!
    if(i == 0){
      ans += arr[i];
      i--;
    }
    else if(i == 1){
      ans += arr[i];
      i-=2;
    }
    else if(i == 2){
      ans += arr[i] + arr[i-1] + arr[i-2];
      i-=3;
    }
    else{
      ans += min(arr[i] + arr[0] + 2*arr[1], 2*arr[0] + arr[i] + arr[i-1]);
      i-=2;

    }
  }
  printf("%d\n", ans);
  return 0;
}
