#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
		int sz = (int)nums.size();
		if(sz == 1) return nums[0];
		if(nums[0] < nums[sz-1]) {
			return nums[0];		
		}
        int left = 0, right = sz - 1;
		while(left <= right) {
			int mid = (left + right) / 2;
			if(nums[mid] > nums[mid+1]) {
				return nums[mid+1];
			} else if(nums[mid] > nums[sz-1]) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return nums[0];
    }
};

int main() {
	vector<int> vec = {4,5,1,2,3};
	Solution sol;
	cout << sol.findMin(vec) << endl;
	return 0;
}
