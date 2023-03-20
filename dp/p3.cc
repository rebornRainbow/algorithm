#include <iostream>
#include <map>
#include <vector>
using namespace std;


class Solution{
public:
Solution(){
    cin >> A >> B;
    LCS = vector<vector<int>>(A.length(),
    vector<int>(B.length(),0));
}

    int getLSC(int i,int j){
        if(i < 0 || j < 0)
            return 0;
        else 
            return LCS[i][j];
    }
    void compute(){
        int n = A.length(),m = B.length();
        for(int ni = 0; ni < n;++ni)
            for(int mi = 0; mi < m;++mi){
                if(A[ni] == B[mi])
                    LCS[ni][mi] = 1 + getLSC(ni-1,mi-1);
                else
                    LCS[ni][mi] = max(getLSC(ni,mi-1),
                    getLSC(ni-1,mi));
            }

        cout << "res :" << LCS[n-1][m-1];
    }
private:
    string A,B;
    vector<vector<int>> LCS;
};

int main(){
    Solution s;
    s.compute();
    return 0;
}