// 48.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int row = (int)matrix.size();
		if (row == 0 || (int)matrix[0].size() == 0) return;
		//int col = (int)matrix[0].size();
		for (int i = 0; i < row / 2; ++i) {
			int len = row - 2 * i;
			for (int j = 0; j < len-1; ++ j) {
				int val = matrix[i][j+i];
				int tar_x = j + i, tar_y = len - 1 + i;
				int cnt = 0;
				while (cnt++ < 4) {
					int tmp = matrix[tar_x][tar_y];
					matrix[tar_x][tar_y] = val;
					val = tmp;
					tar_x -= i;
					tar_y -= i;
					tmp = tar_x;
					tar_x = tar_y + i;
					tar_y = len - 1 - tmp + i;
				}
			}
		}
	}
};
int main()
{
	Solution sol;
	vector<vector<int>> vec = {
  { 5, 1, 9,11},
  { 2, 4, 8,10},
  {13, 3, 6, 7},
  {15,14,12,16}
	};
	sol.rotate(vec);
	for (auto s : vec) {
		for (auto t : s) {
			cout << t << " ";
		}
		cout << endl;
	}
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
