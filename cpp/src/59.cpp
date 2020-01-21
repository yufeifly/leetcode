#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> answer(n,vector<int>(n,0));
    	int fill = 1;
		for(int i=0;i<=(n-1)/2;++i) {
			int start = i , end = n-1-i;
			for(int j=start;j<=end;++j) {
				answer[start][j] = fill++;
			}
			for(int j=start+1;j<=end;++j) {
				answer[j][end] = fill++;
			}
			for(int j=end-1;j>=start;--j) {
				answer[end][j] = fill++;
			}
			for(int j = end-1;j>=start+1;--j) {
				answer[j][start] = fill++;
			}
		}
		return answer;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> answer = sol.generateMatrix(4);
	for(auto s : answer) {
		for(auto t : s) {
			cout << t << " ";
		}
		cout << endl;
	}
	return 0;
}
