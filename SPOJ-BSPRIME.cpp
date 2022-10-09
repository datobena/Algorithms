//Link to the problem: https://www.spoj.com/problems/BSPRIME/
#include <bits/stdc++.h>
#include <cmath>
#include <cstdint>
using namespace std;
#define uint uint32_t
const uint isize = sizeof(uint)*8;
const uint ssize = 150000032/isize;
const uint N = 101865050;
uint lp[N+1];
uint pr[N/4];
uint seq[ssize];
uint pref[ssize];
inline void genPrimes(){
  uint counter = 0;
  for (uint i=2; i <= N; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr[counter] = i;
          counter++;
      }
      for (uint j=0; j < (counter + 1) && pr[j] <= lp[i] && i*pr[j] <= N; ++j) {
          lp[i * pr[j]] = pr[j];
      }
  }
}

inline void initSeq(){
  int counter = 0, i = 0;
  for(uint prime : pr){
    uint cur = prime;
    int lastOne = (int)isize - __builtin_clz(cur);
    int left = (int)isize - counter;
    if(left <= lastOne){
      seq[i] <<= left;
      uint moved = cur>>(lastOne - left);
      seq[i] += moved;
      cur ^= (moved<<(lastOne - left));
      pref[i] = ((i != 0) ? pref[i-1] : 0) + __builtin_popcount(seq[i]);
      counter = 0;
      if(++i == ssize)
        break;
      lastOne -= left;
    }
    seq[i] <<= lastOne;
    seq[i] += cur;
    counter += lastOne;
  }
}


inline void precalc(){
  genPrimes();
  initSeq();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  precalc();
  uint t;
  scanf("%u", &t);
  while(t--){
    uint cur;
    scanf("%u", &cur);
    if(cur == 0) printf("0\n");
    else{
      uint div = (cur - 1)/isize;
      uint rem = cur & (isize - 1);
      uint ans = ((div != 0) ? (pref[div-1]) : 0) + __builtin_popcount(seq[div] >> (isize - rem));
      printf("%u\n", ans);
    }
  }
  return 0;
}
