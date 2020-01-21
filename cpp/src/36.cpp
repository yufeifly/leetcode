// 36.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					//横向只有它一个
					for (int m = 0; m < 9; ++m) {
						if (m == i) continue;
						if (board[m][j] != '.' && board[m][j] == board[i][j]) {

							return false;
						}
					}
					// 纵向只有他它一个
					for (int m = 0; m < 9; ++m) {
						if (m == j) continue;
						if (board[i][m] != '.' && board[i][m] == board[i][j]) {
							return false;
						}
					}
					// 一个小宫格只有它一个
					int headx = (i / 3) * 3;
					int heady = (j / 3) * 3;
					for (int m = headx; m < headx + 3; ++m) {
						for (int n = heady; n < heady + 3; ++n) {
							if (m != i && n != j && board[m][n] == board[i][j]) {
 								return false;
							}
						}
					}
					//
				}
			}
		}
		return true;
	}
};
int main()
{
	vector<vector<char>> vec = {
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
	};
	Solution sol;
	cout << sol.isValidSudoku(vec) << endl;
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
