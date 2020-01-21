#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<vector<int>> answer;
public:
    vector<int> getRow(int numRows) {
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
		return answer[numRows-1];
    }
};

int main() {
	Solution sol;
	vector<int> answer = sol.getRow(3);
	for(auto s : answer) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
