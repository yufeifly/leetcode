#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		if((int)a.size() < (int)b.size()) {
			string tmp = a;
			a = b;
			b = tmp;
		}
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int carry = 0;
		int i = 0;
		for(;i<(int)b.size();++i) {
			int sum = (a[i]-'0') + (b[i]-'0') + carry;
			carry = sum / 2;
			a[i] = (sum % 2) + '0';
		}
		while(i < (int)a.size()) {
			int sum = (a[i]-'0') + carry;
			carry = sum / 2;
			a[i] = sum % 2 +'0';
			if(carry == 0) break;
			++i;
		}
		if(carry == 1) a.push_back('1');
		reverse(a.begin(),a.end());
		return a;
    }
};

int main() {
	string a = "1",b = "111";
	Solution sol;
	cout << sol.addBinary(a,b) << endl;
	return 0;
}
