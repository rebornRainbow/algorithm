#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define NUM 7

struct Block{
  int a,b,c;
  Block(int a,int b,int c):a(a),b(b),c(c){};
};

class Solution{
public:

  void change(int &a,int &b){
    a = a + b;
    b = a - b;
    a = a - b;
  }

  void threeSort(int& a,int & b,int & c){
    if(a > b)
      change(a,b);
    if(c < b)
      change(b,c);
    if(b < a)
      change(a,c);
  }
  
  Solution(int n){
    for(int ni = 0;ni < n; ++ni){
      int a,b,c;
      cin >> a >> b >> c;
      threeSort(a,b,c);
      unblocks.insert(new Block(a,b,c));
      unblocks.insert(new Block(a,c,b));
      unblocks.insert(new Block(b,c,a));
    }
  }
  //对表里面的内容进行排序
  void put(){
    for(auto &elem:unblocks){
      blocks.push_back(elem);
    }
  }



  void solve(){
    put();

    int n = blocks.size();

    RES = vector<int>(n,0);

    blockn = vector<vector<int>>(n,vector<int>());

    for(int ni = 0;ni < n;++ni){
      int tem_max = 0;
      vector<int> tem_n = {};
      for(int mi = 0;mi < ni;++mi){
        if(mi >= 0&&
        blocks[ni]->a > blocks[mi]->a && 
        blocks[ni]->b > blocks[mi]->b &&
        RES[mi] > tem_max){
          tem_max = RES[mi];
          tem_n = blockn[mi];
        }
      }
      RES[ni] = tem_max + blocks[ni]->c;

      blockn[ni] = tem_n;
      blockn[ni].push_back(ni);
    }

    for(int ni = 0;ni < n;++ni)
    {
      cout << "第" << ni << "块积木" << endl;
      cout << "最大高度:" << RES[ni] << endl;
      cout << "用的积木:" ;
      for(auto &index : blockn[ni])
        cout << index << ",";
      cout << endl << endl;
    }
  }

  void show(){
    for(auto &elem:blocks)
      cout << elem->a << ","
      << elem->b << ","
      << elem->c << ","
      << endl;
  }

private:
  
  vector<Block*> blocks;
  vector<int> RES;
  vector<vector<int>> blockn;
  struct comp{
    bool operator()(Block* b1,Block* b2){
      if(b1->a !=  b2->a){
        return b1->a < b2->a;
      }else if(b1->b != b2->b){
        return b1->b < b2->b;
      }else{
        return b1->c < b2->c;
      }
     }
  };
  set<Block*, comp> unblocks;
};

int main(){
    Solution s(NUM);
    s.put();
    s.show();
    s.solve();
    return 0;
}