#include <iostream>
#include <string>

using namespace std;

class Solution {
	private:
		bool valid(string p, int sz) {
			for(int i=0;i<sz;) {
				if(p[i] == '*') ++i;
				else {
					if(i == sz - 1 || p[i+1] != '*') return false;
					else i += 2;
				}
			}
			return true;
		} 
	public:
		int skip(string s, char ch,int ind) {
			int sz = (int)s.size();
			while(ind < sz) {
				if(s[ind] == ch && (ind + 1 < sz && s[ind+1] == '*')) {
					ind += 2;
				} 
				else {
					return ind;
				}
			}
			return ind;
		}

		bool isMatch(string s, string p) {
			int p_sz = (int)p.size();
			string newp = "";
			for(int i=0;i<p_sz;) {
				if(i+1 < p_sz && p[i+1] == '*') {
					newp.append(p,i,2);
					i = skip(p,p[i],i+2);
				} else {
					newp.append(p,i,1);
					++i;
				}
			}
			return Match(s,newp);
		}
		bool Match(string s, string p) {
			int s_sz = (int)s.size(), p_sz = (int)p.size();
			if((s_sz == 0 && p_sz == 0) || (s_sz == 0 && valid(p,p_sz))) return true;
			if((s_sz == 0 && p_sz != 0) || (s_sz != 0 && p_sz == 0)) return false;
			if(s[0] == p[0]) {
				if(p_sz > 1 && p[1] == '*') {
					return Match(s.substr(1),p) || Match(s.substr(1),p.substr(2)) || Match(s,p.substr(2));
				}
				else return Match(s.substr(1),p.substr(1));
			}
			else if(p[0] == '.'){
				if(p_sz > 1 && p[1] == '*') {
					return Match(s.substr(1),p) || Match(s.substr(1),p.substr(2)) || Match(s,p.substr(2));
				}
				else return Match(s.substr(1),p.substr(1));
			}
			else {
				if(p_sz > 1 && p[1] == '*') {
					return Match(s,p.substr(2));
				}
			}
			return false;
		}
};


int main() {
	Solution sol;
	string s = "aaaaaaaaaaaaab", p = "a*a*a*a*a*a*a*a*a*c";
	cout << sol.isMatch(s,p) << endl;
	return 0;
}
