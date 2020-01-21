#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
     	vector<int> base(3,0);
		for(auto i : nums) {
			base[i] += 1;
		}
		int i = 0;
		for(int j = 0;j<base[0];++j) {
			nums[i] = 0;
			++i;
		}
		for(int j=0;j<base[1];++j) {
			nums[i] = 1;
			++i;
		}
		for(int j=0;j<base[2];++j) {
			nums[i] = 2;
			++i;
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
