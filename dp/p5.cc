#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define NUM 4

class Solution{
public:
  Solution(int n):C(n,0){
    for(int ni = 0;ni < n;++ni){
      cin >> C[ni];
    }
  }

  int getRES(int i,int j,int p){
    if(i<0 || j < 0 || i > j)
      return 0;
    else {
      if(p == m){
        return max(getRES(i+1,j,e)+C[i],getRES(i,j-1,e) + C[j]);
      }else {
        return min(getRES(i+1,j,m),getRES(i,j-1,m));
      }
    }
  }

  int solve(){ 
    return getRES(0,C.size()-1,m);
  }

private:
  vector<int> C;
  const int m = 0;
  const int e = 1;
  // map<pair<int,int>> RES[2];没有重复的递归所以不用
    
};

int main(){
  Solution s(NUM);
  cout << "res: " <<s.solve() << endl;
  return 0;
}