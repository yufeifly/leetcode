#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		int p0 = 0,p2 = (int)nums.size() - 1;
		int cur = 0;
		while(cur <= p2) {
			if(nums[cur] == 0) {
				swap(nums[cur],nums[p0]);
				++p0;
				++cur;
			} else if(nums[cur] == 1) {
				++cur;
			} else if(nums[cur] == 2) {
				swap(nums[cur],nums[p2]);
				--p2;
			}
		}
    }
};

int main() {
	vector<int> vec = {2,0,2,1,1,0};
	Solution sol;
	sol.sortColors(vec);
	for(auto i : vec) {
		cout << i << endl;
	}
	return 0;
}
