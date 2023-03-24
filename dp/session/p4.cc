#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define NUM 4

struct Node{
  public:
    int max_m;//表示到这个点最多捡到的蘑菇的数量
    int num;//捡到max_m的路径的数量
    Node():max_m(0),num(1){};
    Node(int max_m,int num):max_m(max_m),num(num){};
};

class Solution{
public:
  Solution(int k):map(NUM,vector<char>(NUM,0)),
  RES(NUM,vector<Node>(NUM,{0,1})){
    for(int ni = 0;ni < NUM;++ni){
      for(int mi = 0;mi < NUM;++mi){
        cin >> map[ni][mi];
      }
    }
  }


  void getNode(int ni,int mi,Node & node){
    if(ni >= 0 && mi >= 0 && map[ni][mi]!='t')
      node = RES[ni][mi];
    else
      node = Node(0,0);
  }

  void solve(){
    
    for(int ni = 0;ni < NUM;++ni){
      for(int mi = 0;mi < NUM;++mi){
        if(ni == 0 && mi == 0){
          RES[ni][mi].max_m = (map[ni][mi] == 'm')?1:0;
          RES[ni][mi].num = 1;
          continue;
        }else if(map[ni][mi] == 't'){
          RES[ni][mi].max_m = 0;
          RES[ni][mi].num = 0;
          continue;
        }
        int sum = 0; 
        if(map[ni][mi] == 'm'){
          Node up,left;
          getNode(ni-1,mi,up);
          getNode(ni,mi-1,left);
          if(up.max_m > left.max_m){
            RES[ni][mi].max_m = up.max_m+1;
            RES[ni][mi].num = up.num;
          }else if(up.max_m < left.max_m){
            RES[ni][mi].max_m = left.max_m+1;
            RES[ni][mi].num = left.num;
          }else{
            RES[ni][mi].max_m = left.max_m+1;
            RES[ni][mi].num = left.num+up.num;
          }
        }else{
          Node up,left;
          getNode(ni-1,mi,up);
          getNode(ni,mi-1,left);
          if(up.max_m > left.max_m){
            RES[ni][mi].max_m = up.max_m;
            RES[ni][mi].num = up.num;
          }else if(up.max_m < left.max_m){
            RES[ni][mi].max_m = left.max_m;
            RES[ni][mi].num = left.num;
          }else{
            RES[ni][mi].max_m = left.max_m;
            RES[ni][mi].num = left.num+up.num;
          }
        }
      }
    }
    cout << "最大捡到的蘑菇的数量" << RES[NUM - 1][NUM - 1].max_m 
      << "最多的路径的数量" << RES[NUM - 1][NUM - 1].num << endl << endl;
  }

  void showMap(){
    cout << "地图:" << endl;
    for(int ni = 0;ni < NUM;++ni){
      for(int mi = 0;mi < NUM;++mi){
        cout << (char)map[ni][mi] << ",";
      }cout << endl;
    }cout << endl;

    cout << "在当前这个点可能捡到的蘑菇的最多的数量" << endl;
    for(int ni = 0;ni < NUM;++ni){
      for(int mi = 0;mi < NUM;++mi){
        cout << RES[ni][mi].max_m << ",";
      }cout << endl;
    }cout << endl;
    cout << "在当前这个点捡到最多蘑菇可能的路径的数量" << endl; 
    for(int ni = 0;ni < NUM;++ni){
      for(int mi = 0;mi < NUM;++mi){
        cout << RES[ni][mi].num << ",";
      }cout << endl;
    }cout << endl;
  }

private:
  vector<vector<char>> map;
  vector<vector<Node>> RES;
    
};

int main(){
    Solution s(2);
    s.solve();
    s.showMap();
    return 0;
}