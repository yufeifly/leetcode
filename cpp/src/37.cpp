// 37.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		Sudoku(board);
	}
	bool Sudoku(vector<vector<char>>& board) {
		// 找到一个空位
		int row = 0, col = 0;
		bool vacancy = false;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					row = i; col = j; 
					vacancy = true;break;
				}
			}
			if (vacancy) break;
		}
		if (vacancy == false) return true;
 		// 找到这个空位所有可能的取值
		bool occupied[10] = { 0 };
		// 横向
		for (int i = 0; i < 9; ++i) {
			char ch = board[row][i];
			if (ch != '.') occupied[ch - '0'] = true;
		}
		// 纵向
		for (int i = 0; i < 9; ++i) {
			char ch = board[i][col];
			if (ch != '.') occupied[ch - '0'] = true;
		}
		// 小宫格
		int headx = (row / 3) * 3;
		int heady = (col / 3) * 3;
		for (int i = headx; i < headx + 3; ++i) {
			for (int j = heady; j < heady + 3; ++j) {
				char ch = board[i][j];
				if (ch != '.') occupied[ch - '0'] = true;
			}
		}
		//
		vector<char> candidate;
		for (int i = 1; i < 10; ++i) {
			if (!occupied[i]) candidate.push_back(i+'0');
		}
		if ((int)candidate.size() == 0) {
			return false;
		}
		//
		for (int i = 0; i < (int)candidate.size(); ++i) {
			board[row][col] = candidate[i];
			//print(board);
			if (Sudoku(board)) return true;
			board[row][col] = '.';
		}
		return false;
	}

	void print(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
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
	sol.solveSudoku(vec);
	sol.print(vec);
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
