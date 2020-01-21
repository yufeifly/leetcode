// 51.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	int sz;
	vector<vector<int>> map;
	int answer;
public:
	int totalNQueens(int n) {
		sz = n;
		map.resize(n);
		for (int i = 0; i < n; ++i) {
			map[i].resize(n, 0);
		}
		for (int i = 0; i < n; ++i) {
			map[0][i] = 1;
			queue(1);
			map[0][i] = 0;
		}
		return answer;
	}
	void queue(int lev) {
		if (lev == sz) {
			answer += 1;
		}
		for (int i = 0; i < sz; ++i) {
			if (!collision(lev, i)) {
				map[lev][i] = 1;
				queue(lev + 1);
				map[lev][i] = 0;
			}
		}
	}

	bool collision(int r, int c) {
		for (int i = 0; i < sz; ++i) {
			if (map[i][c] == 1) {
				return true;
			}
		}
		int t_r = r, t_c = c;
		while (t_r >= 0 && t_c >= 0) {
			if (map[t_r][t_c] == 1) return true;
			--t_r;
			--t_c;
		}
		t_r = r; t_c = c;
		while (t_r >= 0 && t_c < sz) {
			if (map[t_r][t_c] == 1) return true;
			--t_r;
			++t_c;
		}
		t_r = r; t_c = c;
		while (t_r < sz && t_c >= 0) {
			if (map[t_r][t_c] == 1) return true;
			++t_r;
			--t_c;
		}
		t_r = r; t_c = c;
		while (t_r < sz && t_c < sz) {
			if (map[t_r][t_c] == 1) return true;
			++t_r;
			++t_c;
		}
		return false;
	}
};
int main()
{
	Solution sol;
	
	cout << sol.totalNQueens(4) << endl;
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
