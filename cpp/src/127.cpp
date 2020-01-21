#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
	bool dis_one(string &a, string &b) {
		int diff = 0;
		for(int i=0;i<(int)a.size();++i) {
			if(a[i] != b[i]) {
				++diff;
				if(diff > 1) return false;
			}
		}
		return (diff == 1);
	}
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);
		int sz = (int)wordList.size();
 		vector<int> distance(sz,-1);
		distance[sz-1] = 0;

		int target_id = -1;
		
		for(int i=0;i<sz-1;++i) {
			if(wordList[i] == endWord) {
				target_id = i;
				break;
			}
		}
		if(target_id == -1) return 0;

		queue<int> que;
		que.push(sz-1);

		while(!que.empty()) {
			int tmp = que.front();
			que.pop();
			for(int i=0;i<sz-1;++i) {
				if(distance[i] == -1 && dis_one(wordList[tmp],wordList[i])) {
					que.push(i);
					distance[i] = distance[tmp] + 1;
				}
			}
		}
		
		if(distance[target_id] == -1) return 0;
		return distance[target_id] + 1;
		
	}
};

int main() {
	Solution sol;
	string beg = "hit",end = "cog";
	vector<string> vec = {"hot","dot","dog","lot","log","cog"};
	cout << sol.ladderLength(beg,end,vec) << endl;

	return 0;
}
