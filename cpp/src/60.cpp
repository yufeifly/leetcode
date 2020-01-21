#include <iostream>
#include <vector>
#include <string>
using namespace std;

// class Solution { // 递归 全排列采用交换方式顺序特殊，不是按照大小顺序排列的。
// private:
//     int cnt;
//     int _k;
//     int _n;
//     vector<int> answer;
//     void printV() {
//         for(auto s : answer) {
//             cout << s << " ";
//         }
//         cout << endl;
//     }
//     bool permutation(int lev) {
//         if(lev == _n) {
//             ++cnt;
//             printV();
//             //if(cnt == _k) return true;
//         }else {
//             for(int i=lev;i<_n;++i) {
//                 int tmp= answer[lev];
//                 answer[lev] = answer[i];
//                 answer[i] = tmp;
//                 if(permutation(lev+1)) {
//                     //return true;
//                 }
//                 tmp = answer[lev];
//                 answer[lev] = answer[i];
//                 answer[i] = tmp;
//             }
//         }
//         return false;
//     }
// public:
//     string getPermutation(int n, int k) {
//         cnt = 0;
//         _k = k;
//         _n = n;
//         for(int i=0;i<n;++i) {
//             answer.push_back(i+1);
//         }
//         permutation(0);
//         string str;
//         for(auto elem:answer) {
//             str.push_back(elem+'0');
//         }
//         return str;
//     }
// };
class Solution {
private:
    int cnt;
    vector<int> answer;
    void printV() {
        for(auto s : answer) {
            cout << s << " ";
        }
        cout << endl;
    }
    bool permutation(int lev,int n,int k, vector<bool> &visit) {
        if(lev == n) {
            ++cnt;
            //printV();
            if(cnt == k) return true;
        }else {
            for(int i=1;i<=n;++i) {
                if(!visit[i]) {
                    visit[i] = true;
                    answer.push_back(i);
                    if(permutation(lev+1,n,k,visit)) {
                        return true;
                    }
                    answer.pop_back();
                    visit[i] = false;
                }
            }
        }
        return false;
    }
public:
    string getPermutation(int n, int k) {
        cnt = 0;
        vector<bool> visit(n+1,0);
        permutation(0,n,k,visit);
        string str;
        for(auto elem:answer) {
            str.push_back(elem+'0');
        }
        return str;
    }
};
int main() {
    Solution sol;
    cout << sol.getPermutation(3,5) << endl;
    return 0;
}