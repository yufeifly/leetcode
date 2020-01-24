#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	string delExtraZero(string s) {
		int sz = (int)s.size();
		bool flag = false;
		for(int i=0;i<sz;++i) {
			if(s[i] != '0') {
				flag = true;
				break;
			}
		}
		if(flag == false) return "0";

		if(s[0] == '0') {
			for(int i=0;i<sz;++i) {
				if(s[i] != '0') {
					return s.substr(i);
				}
			}
		}
		return s;
	}

	vector<string> sp(string s) {
		vector<string> ret;
		if(s[(int)s.size() - 1] != '.') {
			s += '.';
		}
		int sz = (int)s.size();
		int head = 0;
		for(int i=0;i<sz;++i) {
			if(s[i] == '.') {
				ret.push_back(delExtraZero(s.substr(head,i-head)));
				head = i + 1;
			}
		}
		return ret;
	}

	void print(vector<string> vec) {
		for(auto s : vec) {
			cout << s << " ";
		}
		cout << endl;
	}
	bool notAllZero(int st, vector<string>&vec) {
		for(int i = st; i< (int)vec.size();++i) {
			string s = vec[i];
			if(!((int)s.size() == 1 && s[0] == '0')) {
				return true;
			}
		}
		return false;
	}
public:
    int compareVersion(string version1, string version2) {
    	vector<string> v1 = sp(version1);
		vector<string> v2 = sp(version2);
	   	print(v1);
		print(v2);
		int v1_sz = (int)v1.size();
		int v2_sz = (int)v2.size();
		int i=0;
		for(;i<v1_sz && i < v2_sz;++i) {
			string s1 = v1[i], s2 = v2[i];
			if(s1.size() == s2.size()) {
				for(int i=0;i<(int)s1.size();++i) {
					if(s1[i] > s2[i]) return 1;
					else if(s1[i] < s2[i]) return -1;
				}
			} else if(s1.size() > s2.size()) {
				return 1;
			} else {
				return -1;
			}
		}
		if(v1_sz > v2_sz) {
			if(notAllZero(i,v1)) {
				return 1;
			} else return 0;
		} else if(v1_sz < v2_sz){
			if(notAllZero(i,v2)) {
				return -1;
			} else return 0;
		}
		return 0;
    }
};

int main() {
	string version1 = "1.0";
	string version2 = "1.0.0";
	Solution sol;
	cout << sol.compareVersion(version1,version2) << endl;
	return 0;
}
