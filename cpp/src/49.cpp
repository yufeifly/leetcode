#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
private:
    vector<vector<string>> answer;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if((int)strs.size() <= 0) return answer;
		map<string,vector<string>> mp;
		vector<string> tmp = {strs[0]};
		string sorted = strs[0];
		sort(sorted.begin(),sorted.end());
		mp.insert(pair<string, vector<string>>(sorted,tmp));
		
		for(int i=1;i<(int)strs.size();++i) {
			string sorted = strs[i];
			sort(sorted.begin(),sorted.end());
			if(mp.find(sorted) != mp.end()) { // found
				mp[sorted].push_back(strs[i]);
			} else { // not found
				vector<string> tmp = {strs[i]};
				mp.insert(pair<string, vector<string>>(sorted,tmp));
			}
		}
		//
		map<string, vector<string>>::iterator iter;
		for(iter=mp.begin();iter!=mp.end();++iter) {
			answer.push_back(iter->second);
		}
		return answer;
    }
};

int main() {
	Solution sol;
	vector<string> vstr = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> answer = sol.groupAnagrams(vstr);
	for(auto s : answer) {
		for(auto t : s) {
			cout << t << " ";
		}
		cout << endl;
	}
	return 0;
}
