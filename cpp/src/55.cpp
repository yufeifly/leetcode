#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int cur = 0;
		int tmp_loc;

		while ((nums[cur] + cur < (int)nums.size() - 1)) {
			int tmp_max = -1;
			if (nums[cur] == 0) return false;
			for (int i = 1; i <= nums[cur]; ++i) {
				if (nums[i + cur] + i + cur > tmp_max) {
					tmp_max = nums[i + cur] + i + cur;
					tmp_loc = i + cur;
				}
			}
			if (tmp_max == 0) return false;
			cur = tmp_loc;
		}
		return true;
	}
};
//
int main() {
	Solution s;
	//vector<int> vec = { 2,3,1,1,4 };
	vector<int> vec = { 5,9,3,2,1,0,2,3,3,1,0,0};
	cout << s.canJump(vec) << endl;
	return 0;
}