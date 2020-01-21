#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
    	if((int)s.size() <= 0) return 0;
		int answer = 0;
		int i = (int)s.size()-1;
		for(;i>=0;--i) {
			if(s[i] != ' ') break;
		}
		int j = i;
		for(;j>=0;--j) {
			if(s[j] != ' ') {
				++answer;
			}
			else break;
		}
		return answer;
    }
};

int main() {
	string s = "a";
	Solution sol;
	cout << sol.lengthOfLastWord(s) << endl;
	return 0;
}
