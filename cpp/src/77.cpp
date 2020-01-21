#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> answer;
    vector<int> vec;
    void comb(int lev,int n,int k,vector<bool>&visit){
        if(lev == k) {
            answer.push_back(vec);
            return ;
        } else {
            int st = ((int)vec.size() == 0) ? 1:vec[(int)vec.size() - 1];
            for(int i=st;i<=n;++i) {
                if(!visit[i]) {
                    visit[i] = true;
                    vec.push_back(i);
                    comb(lev+1,n,k,visit);
                    vec.pop_back();
                    visit[i] = false;
                }
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<bool> visit(n+1,0);
        comb(0,n,k,visit);
        return answer;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> answer = sol.combine(4,2);
    for(auto s : answer) {
        for(auto t : s) {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}