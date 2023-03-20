#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;


class Solution{
public:
Solution(int n):n(n),value(n,0),RES(n,0){
    for(auto & elem : value)
    {
        cin >> elem;
    }
}

int getRES(int n)
{
    if(n < 0)
        return 0;
    else 
        return RES[n];
}

void bowling()
{
    for(int ni = 0;ni < n;++ni)
    {
        int tem = max( getRES(ni-1)+value[ni],
        getRES(ni-2)+value[ni] * value[ni-1] );
        int max_on = max( tem, getRES(ni-1) );
        RES[ni] = max_on;
    }
    cout  << "bowling:" << RES[n-1] << endl;
}

private:
    int n;
    vector<int> value;
    vector<int> RES;
};

int main(){
    int  n;
    cin >>n;
    Solution s1(n);
    s1.bowling();
    return 0;
}