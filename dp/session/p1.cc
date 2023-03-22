#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define NUM 4

struct Node{
public:
  int h_m;
  vector<int> play_days;
};

class Solution{
public:
  Solution(int n):n(n),T(n,0),RES(n,{0,{}}){
    for(int ni = 0;ni < n;++ni)
      cin >> T[ni];
    cout << "温度:";
    for(int ni = 0;ni < n;++ni)
      cout << T[ni] << ","; 
    cout << endl << endl;
  }


  int getT(int i){
    if(i >= 0 && i < n)
      return T[i];
    return 0;
  }

  int getRES(int i){
    if(i >= 0 && i < n)
      return RES[i].h_m;
    return 0;
  }
  


  void solve(){
    for(int ni = 0;ni < n;++ni){
      int R1 = getRES(ni-1),
      R2 = getT(ni) + getT(ni-1) + getRES(ni-3),
      R3 = getT(ni) + getRES(ni-2);
      if(R1 >= R2&& R1 >= R3){
        RES[ni].h_m = R1;
        if(ni-1 >= 0)
          RES[ni].play_days = RES[ni - 1].play_days;
      }else if(R2 >= R1 && R2 >= R3){
        RES[ni].h_m = R2;
        if(ni - 3 >= 0)
          RES[ni].play_days = RES[ni - 3].play_days;
        if(ni - 1 >= 0)
          RES[ni].play_days.push_back(ni-1);
        RES[ni].play_days.push_back(ni);
      }else {
        RES[ni].h_m = R3;
        if(ni - 2 >= 0)
          RES[ni].play_days = RES[ni - 2].play_days;
        RES[ni].play_days.push_back(ni);
      }
    }

  for(int ni = 0;ni < n;++ni)
  {
    cout << 0 << "--" << ni << "玩的天:";
    for(auto & elem : RES[ni].play_days){
      cout << elem 
      << ",";
    }cout << endl;
    
    cout << "最大的幸福值:"
    << RES[ni].h_m 
    << endl << endl;
  }
}

private:
  int n;
  vector<int> T;
  vector<Node> RES;
    
};

int main(){
  Solution s(NUM);
  s.solve();
  return 0;
}