#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int sz = (int)nums.size();
   		vector<int> dp(sz,0);
		dp[0] = nums[0];
		int max = dp[0];
		for(int i=1;i<sz;++i) {
			if(dp[i-1] > 0) dp[i] = dp[i-1] + nums[i];
			else dp[i] = nums[i];
			if(dp[i] > max) max = dp[i];
		}
		return max;
    }
};

int main () {
	Solution sol;
	vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
	cout << sol.maxSubArray(vec) << endl;
	return 0;
}
