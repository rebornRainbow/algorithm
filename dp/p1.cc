#include <iostream>
#include <map>
using namespace std;


/**
    解决斐波那契数列
*/

/**
    时间:T(n) = T(n-1)+T(n-2) + O(1)
    指数级别
*/
class Solution1{
public:
    int Fib(int n){
        if(n == 1||n == 2){
            return 1;
        }else{
            return Fib(n-1)+Fib(n-2);
        }
    }

};

/**
时间:O(n) :因为每个节点1次
*/
class Solution2{
public:
    Solution2(){};
    int Fib(int n){
        if(n == 1||n == 2){
            return 1;
        }else{
            if(!memo.count(n-1))
                memo[n-1] = Fib(n-1);
            if(!memo.count(n-2))
                memo[n-2] = Fib(n-2);
            return memo[n-1]+memo[n-2];
        }
    }
private:
    map<int,int> memo;
};


int main(){
    int n  = 0;
    Solution2 s2;
    cin >> n; 
    cout << "res: "<< s2.Fib(n) << endl;
    return 0;
}