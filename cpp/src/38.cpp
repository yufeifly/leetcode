#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int count(string &s,int ind) {
		char ch = s[ind];
		int i;
		for(i=ind+1;i<(int)s.size();++i) {
			if(s[i] != ch) {
				break;
			}
		}
		return i - ind;
	}
    string countAndSay(int n) {
       string root = "1";
	   for(int j=0;j<n-1;++j) {
		   string tmp = "";
		   for(int i=0;i<(int)root.size();) {
			   int c = count(root,i);
			   tmp += to_string(c) + root[i];
			   i += c;
		   }
		   root = tmp;
	   }
	   return root;
    }
};

int main(){
	Solution sol;
	cout << sol.countAndSay(5) << endl;
	return 0;
}
