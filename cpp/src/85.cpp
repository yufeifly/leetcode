// 85.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int answer = 0;
		int row = (int)matrix.size();
		if (row <= 0) return 0; 
		int col = (int)matrix[0].size();
		vector<vector<int>> dp(row,vector<int>(col,0));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (matrix[i][j] == '1') {
					if (j >= 1 && matrix[i][j - 1] == '1') dp[i][j] = dp[i][j - 1] + 1;
					else dp[i][j] = 1;
				}
				else dp[i][j] = 0;
			}
		}
		//
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (dp[i][j] > 0) {
					int x = i;
					int tmp_max = 0;
					int cur_len = dp[i][j];
					while (x >= 0 && dp[x][j] > 0) {
						cur_len = min(cur_len, dp[x][j]);
						int tmp = (i-x+1)* cur_len;
						tmp_max = max(tmp_max, tmp);
						--x;
					}
					answer = max(tmp_max,answer);
				}
			}
		}
		return answer;
	}
};

int main()
{
	vector<vector<char>> vec = {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'}
	};
	Solution sol;
	cout << sol.maximalRectangle(vec);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
