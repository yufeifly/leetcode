#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<vector<int>> answer;
public:
    vector<vector<int>> generate(int numRows) {
		for(int i=0;i<numRows;++i) {
			vector<int> tmp;
			tmp.push_back(1);
			if(i == 1){
				tmp.push_back(1);
			} 
			else if(i> 1){
				for(int j=1;j<=i-1;++j){
					tmp.push_back(answer[i-1][j-1]+answer[i-1][j]);
				}
				tmp.push_back(1);
			}
			answer.push_back(tmp);
		}
		return answer;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> answer = sol.generate(5);
	for(auto s : answer) {
		for(auto t : s) {
			cout << t << " ";
		}
		cout << endl;
	}
	return 0;
}
