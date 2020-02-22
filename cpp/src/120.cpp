#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		int rows = (int)triangle.size();
		for(int i=1;i<rows;++i) {
			int cols = (int)triangle[i].size();
			triangle[i][0] += triangle[i-1][0];
			for(int j=1;j<cols-1;++j) {
				triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
			}
			triangle[i][cols-1] += triangle[i-1][cols-2];
		}
		int minV = triangle[rows-1][0];
		for(int i=1;i<(int)triangle[rows-1].size();++i) {
			minV = min(minV, triangle[rows-1][i]);
		}
		return minV;
    }
};

int main() {
	vector<vector<int>> vec = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};
	Solution sol;
	cout << sol.minimumTotal(vec) << endl;
	return 0;
}
