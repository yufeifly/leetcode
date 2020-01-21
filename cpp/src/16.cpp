#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
 		sort(nums.begin(),nums.end());
		int sz = (int)nums.size();
		int ans = nums[0] + nums[1] + nums[2];
		for(int i=0;i<sz-2;++i) {
			for(int j=i+1;j<sz-1;++j) {
				for(int k=j+1;k<sz;++k) {
					int tmp = nums[i] +nums[j] +nums[k];
					if(abs(tmp - target) < abs(ans - target)) {
						ans = tmp;
					}
					if(tmp > target) {
						break;
					}
					if(tmp == target) {
						return tmp;
					}
				}
			}
		}
		return ans;
    }
};

int main() {
	Solution sol;
	vector<int> vec = {-1,2,1,-4};
	cout << sol.threeSumClosest(vec,1) << endl;
	return 0;

}
