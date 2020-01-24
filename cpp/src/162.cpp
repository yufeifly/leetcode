#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int sz = (int)nums.size();
		if(sz == 1) return 0;
		int left = 0, right = (int)nums.size()-1;
		while(left <= right) {
			int mid = (left + right) / 2;
			if(mid - 1 < 0) {
				if(nums[mid] > nums[mid+1])
					return mid;
				else {
					left = mid + 1;
				}
			} else if(mid >= sz-1) {
				if(nums[mid]> nums[mid-1]){
					return mid;
				} else {
					right  = mid - 1;
				}
			} else if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
				return mid;
			} else if(nums[mid] < nums[mid+1] && nums[mid] > nums[mid-1]) {
				left = mid + 1;
			} else if(nums[mid] > nums[mid+1] && nums[mid] < nums[mid-1]) {
				right =mid - 1;
			} else {
				right = mid - 1;
			}
		}
		return 0;
    }
};


int main() {
	Solution sol;
	vector<int> vec = {1};
	cout << sol.findPeakElement(vec) << endl;
	return 0;
}
