#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
		int carry = 0;
		for(int i=0;i<(int)digits.size();++i) {
			digits[i] += (i == 0) ? 1 + carry : carry;
			carry = digits[i] / 10;
			if(carry == 0) break;
			digits[i] -= carry * 10;
		}
		if(carry > 0) digits.push_back(carry);
		reverse(digits.begin(),digits.end());
		return digits;
    }

};

int main() {
	Solution sol;
	vector<int> vec = {9,9};
	vector<int> answer = sol.plusOne(vec);
	for(auto s : answer) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
