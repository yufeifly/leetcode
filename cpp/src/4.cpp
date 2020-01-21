#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if((int)nums1.size() > (int)nums2.size()) {
			vector<int> tmp = nums1;
			nums1 = nums2;
			nums2 = tmp;
		}
	//	print(nums1);
	//	print(nums2);
		int m = (int)nums1.size(), n = (int)nums2.size();
		int i_min = 0, i_max = m;
		int half_len = (m + n + 1) / 2;
		while(i_min <= i_max) {
			int i = (i_max + i_min) / 2;
			int j = half_len - i;
			if(i < i_max && nums2[j-1] > nums1[i]) {
				i_min = i + 1;
			}
			else if(i > i_min && nums1[i-1] > nums2[j]) {
				i_max = i - 1;
			}
			else {
				int maxleft = 0;
				if(i == 0) {
					maxleft = nums2[j-1];
				} else if(j == 0) {
					maxleft = nums1[i-1];
				} else {
					maxleft = max(nums1[i-1],nums2[j-1]);
				}
				if((m + n) % 2) {
					return maxleft;
				}
				int minright = 0;
				if(i == m) {
					minright = nums2[j];
				} else if(j == n) {
					minright = nums1[i];
				} else {
					minright = min(nums1[i],nums2[j]);
				} 
				return (maxleft + minright) / 2.0;

			}
		}
 		return 0.0;       
    }
//	void print(vector<int> &nums) {
//		for(auto s : nums) {
//			cout << s << " ";
//		}
//		cout << endl;
//	}
};

int main() {
	vector<int> nums1 = {1,2,5};
	vector<int> nums2 = {3,4};
	Solution sol;
	cout << sol.findMedianSortedArrays(nums1,nums2) << endl;
    return 0;
}
