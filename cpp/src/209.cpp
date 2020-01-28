#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int st = 0, ed = 0;
		int sz = (int)nums.size();
		int sum = 0;
		int answer = sz + 1;
		for(;ed < sz;++ed) {
			sum += nums[ed];
			if(sum >= s) {
				while(sum - nums[st] >= s) {
					sum -= nums[st];
					++st;
				}
				if(ed - st + 1 < answer) {
					answer = ed - st + 1;
				}
			}
		}
		return (answer == sz + 1)? 0 : answer;
    }
};

int main() {
	vector<int> vec = {2,3,1,2,4,3};
	Solution sol;
	cout << sol.minSubArrayLen(7,vec) << endl;
	return 0;
}
