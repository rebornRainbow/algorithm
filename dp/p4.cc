#include <iostream>
#include <map>
#include <vector>
using namespace std;


class Solution{
public:
Solution(){
    cin >> str;
    RES = vector<int>(str.length(),0);
}

void solve(){
    int n = str.length();
    int res = 0;
    for(int ni = 0; ni < n;++ni){
        int max = 0;
        for(int ti = 0; ti <= ni;++ti){
            if(str[ti] < str[ni] && RES[ti] > max){
                max = RES[ti];
            }
        }

        RES[ni] = max + 1;
        if(RES[ni]  > res){
            res = RES[ni];
        }
    }

    cout << "res: " << res << endl;
}

private:
    string str;
    vector<int> RES;    
};

int main(){
    Solution s;
    s.solve();
    return 0;
}