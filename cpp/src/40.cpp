#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> answer;
	vector<int> tmp;
public:
	void dfs(int cur,int st, int target, vector<int>& candidates) {
        int val = 0;
		for (int i = st; i < (int)candidates.size(); ++i) {
            if(val == candidates[i]) {
                continue;
            }
			if (cur + candidates[i] == target) {
				tmp.push_back(candidates[i]);
				answer.push_back(tmp);
                val = tmp[(int)tmp.size() - 1];
				tmp.pop_back();
			}
			else if (cur + candidates[i] < target) {
				tmp.push_back(candidates[i]);
				dfs(cur + candidates[i], i+1,target, candidates);
                val = tmp[(int)tmp.size() - 1];
				tmp.pop_back();
			}
			else {
				break;
			}
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(0,0,target,candidates);
		return answer;
	}
};

int main() {
    Solution sol;
    vector<int> vec = {2,5,2,1,2};
    vector<vector<int>>answer =  sol.combinationSum2(vec,5);
    for(auto s : answer) {
        for(auto t: s) {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}