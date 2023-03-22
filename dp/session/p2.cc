#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


/**
 * @brief 
 * 设置交换两个相邻数的代价为1
 * 插入或者删除的代价为3
 */

struct Node{
public:
  int m_cost;//到这个节点所花费的最小的代价
  vector<string> op;//表示执行的操作
  Node(int m_cost,vector<string> op):m_cost(m_cost),op(op){}



};

class Solution{
public:
  Solution(){
    cin >> fileA >> fileB;
    RES = vector<vector<Node>>(fileA.length(),
    vector<Node>(fileB.length(),Node(0,{})));
  }

  char getFileLine(string file,int i){
    if(i < 0)
      return 0;
    else 
      return file[i];
  }

  void solve(){
    int a =fileA.length(),b = fileB.length();
    for(int ai = 0;ai < a;++ai)
      for(int bi = 0;bi < b;++bi){
        int cost_c = INT_MAX;
        vector<string> op_c;

        if(fileA[ai] == fileB[bi]){
          if(ai - 1 >= 0 && bi - 1 >= 0){
            cost_c = RES[ai-1][bi-1].m_cost;
            op_c = RES[ai-1][bi-1].op;
          }else if(ai - 1 >= 0 && bi - 1 < 0){
            cost_c = ai * 3;
            for(int mi = 0;mi < ai;++mi)
              op_c.push_back("删除a:0");
          }else if(bi - 1 >= 0 && ai - 1 < 0){
            cost_c = bi * 3;
            for(int mi = 0;mi < bi;++mi)
              op_c.push_back("删除b:0");
          }else{
            cost_c = 0;
          }
        }else if(ai - 1 >= 0 && bi - 1 >= 0 
            && fileA[ai-1] == fileB[bi] 
            && fileA[ai] == fileB[bi-1]){
              int tem_cost = 0;
              vector<string> tem_op;
              if(ai-2 >= 0 && bi-2 >= 0){
                tem_cost = RES[ai-2][bi-2].m_cost;
                tem_op = RES[ai-2][bi-2].op;
              }else{
                if(ai-2 >= 0 && bi-2 < 0){
                  tem_cost = (ai-1)*3;
                  for(int mi = 0;mi < ai -1;++mi)
                    tem_op.push_back("删除a:0");
                }else if(bi-2 >= 0 && ai-2 < 0){
                  tem_cost = (bi - 1)*3;
                  for(int mi = 0;mi < bi -1;++mi)
                    tem_op.push_back("删除b:0");
                }else{
                  tem_cost = 0;
                }
              }
              tem_cost +=  1;
              if(tem_cost < cost_c)
              {
                cost_c = tem_cost;
                tem_op.push_back(string("交换fileA的")+
                to_string(ai)+string(",")+to_string(ai-1)+
                string("/交换fileB的") + to_string(bi)
                + string(",") + to_string(bi-1));
                op_c = tem_op;
              }
        }else{
          int tem_cost = INT_MAX;
          vector<string> tem_op;
          int tem_cost1 = INT_MAX;
          vector<string> tem_op1;
          int tem_cost2 = INT_MAX;
          vector<string> tem_op2;
          if(ai - 1 >= 0)
          {
            tem_cost1 = RES[ai-1][bi].m_cost;
            tem_op1 = RES[ai-1][bi].op;
          }else{
            tem_cost1 = (bi+1)*3;
            for(int mi = 0;mi < bi + 1;++mi){
              tem_op1.push_back("删除b:0");
            }
          }
          if(bi - 1 >= 0)
          {
            tem_cost2 = RES[ai][bi-1].m_cost;
            tem_op2 = RES[ai][bi - 1].op;
          }else{
            tem_cost2 = (ai+1)*3;
            for(int mi = 0;mi < ai + 1;++mi){
              tem_op2.push_back("删除a:0");
            }
          }
          if(tem_cost1 < tem_cost2){
            tem_cost = tem_cost1 + 3;
            tem_op1.push_back(string("删除a")+to_string(ai));
            tem_op = tem_op1;
          }else{
            tem_cost = tem_cost2 + 3;
            tem_op2.push_back(string("删除b")+to_string(bi));
            tem_op = tem_op2;
          }
          if(tem_cost < cost_c)
          {
            cost_c = tem_cost;
            op_c = tem_op;
          }
          
        }

        if(cost_c == INT_MAX)
          cost_c = 0;
        RES[ai][bi].m_cost = cost_c;
        RES[ai][bi].op = op_c;
    }
    cout << fileA.length() << ":" << fileA << endl;
    cout << fileB.length() << ":" << fileB << endl;
    cout << "结果"
    << RES[a-1][b-1].m_cost
    << endl;
    for(auto & op:RES[a-1][b-1].op){
      cout << op << ";";
    }cout << endl;
    cout << "一共要操作:" 
    << RES[a-1][b-1].op.size() 
    << "次" << endl;
  }
private:
  string fileA,fileB;
  vector<vector<Node>> RES;
    
};

int main(){
    Solution s;
    s.solve();
    return 0;
}