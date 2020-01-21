#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		for (int i = 0; i < (int)nums.size()-2; ++i) {
			if (i == 0 || nums[i] > nums[i - 1]) {
				int l = i + 1, r = (int)nums.size() - 1;
				while (l < r) {
					if (0 == nums[i] + nums[l] + nums[r]) {
						res.push_back(vector<int>{nums[i], nums[l], nums[r]});
						++l;
						--r;
						while (l < r && nums[l] == nums[l - 1]) ++l;
						while (l < r && nums[r] == nums[r + 1]) --r;
					}
					else if(nums[i] + nums[l] + nums[r] > 0){
						--r;
					}
					else {
						++l;
					}
				}
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> num = { -1,0,1,2,-1,4 };
	vector<vector<int>> ans = s.threeSum(num);
	for (int i = 0; i < (int)ans.size(); ++i) {
		for (int j = 0; j < (int)ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}