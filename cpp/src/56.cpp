#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	static bool cmp(vector<int> &a, vector<int> &b) {
		return a[0] < b[0];
	}
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
		for(int i=1;i<(int)intervals.size();) {
			if(intervals[i][1] <= intervals[i-1][1]) { //delete diractly
				intervals.erase(intervals.begin() + i);
			} else if(intervals[i][0] <= intervals[i-1][1]) { // merge
				intervals[i-1][1] = intervals[i][1];
				intervals.erase(intervals.begin() + i);
			} else { // split
				++i;
			}
		}
		return intervals;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> vec = {{2,6},{1,3},{8,10},{15,18}};
	vector<vector<int>> answer = sol.merge(vec);
	for(auto s:answer) {
		for(auto t : s) {
			cout << t << " ";
		}
		cout << endl;
	}
	return 0;
}
