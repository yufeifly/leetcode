#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		int left = 0, right = (int)s.size()-1;
		while(left < right) {
			while(!isalnum(s[left]) && left < right) {
				++left;
			}
			while(!isalnum(s[right]) && left < right) {
				--right;	
			}
			if(isupper(s[left])) s[left] = s[left] - 'A' + 'a';
			if(isupper(s[right])) s[right] = s[right] - 'A' + 'a';
			if(s[left] != s[right]) {
				return false;
			}
			++left;
			--right;
		}
		return true;
    }
};

int main() {
	Solution sol;
	cout << sol.isPalindrome("A man, a plan, a canal: Panama")<< endl;
	return 0;
}
