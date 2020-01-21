#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int sz = (int)nums.size();
        vector<int> left(sz);
		vector<int> right(sz);
		vector<int> answer(sz);
		int tmp = 1;
		for(int i=0;i<sz;++i) {
			left[i] = tmp;
			tmp *= nums[i];
		}
		tmp = 1;
		for(int i=sz-1;i>=0;--i) {
			right[i] = tmp;
			tmp *= nums[i];
		}
		for(int i=0;i<sz;++i) {
			answer[i] = left[i] * right[i];
		}
		return answer;
    }
};

int main() {
	Solution sol;
	vector<int> vec = {1,2,3,4};
	vector<int> answer = sol.productExceptSelf(vec);
	for(auto s : answer) {
		cout << s << endl;
	}
	return 0;
}
