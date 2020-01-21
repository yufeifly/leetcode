// 115.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int t_sz = (int)t.size(), s_sz = (int)s.size();
		vector<vector<long long>> vec(t_sz+1, vector<long long>(s_sz+1));
		for (int i = 0; i <= s_sz; ++i) vec[0][i] = 1;
		for (int i = 1; i <= t_sz; ++i) vec[i][0] = 0;
		for (int i = 0; i < t_sz; ++i) {
			for (int j = 0; j < s_sz; ++j) {
				if (s[j] == t[i]) {
					vec[i + 1][j + 1] = vec[i][j] + vec[i+1][j];
				}
				else {
					vec[i + 1][j + 1] = vec[i + 1][j];
				}
			}
		}
		return vec[t_sz][s_sz];
	}
};
int main()
{
	Solution sol;
	cout << sol.numDistinct("rabbbit", "rabbit") << endl;
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
