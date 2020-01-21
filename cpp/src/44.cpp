// 44.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int s_sz = (int)s.size(), p_sz = (int)p.size();
		vector<vector<bool>> dp(p_sz + 1, vector<bool>(s_sz + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= p_sz; ++i) {
			if (p[i - 1] == '*') dp[i][0] = dp[i-1][0];
		}
		//
		for (int i = 1; i <= p_sz; ++i) {
			for (int j = 1; j <= s_sz; ++j) {
				if (p[i - 1] == s[j - 1] || p[i - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
				else if (p[i - 1] == '*') {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i-1][j-1];
				}
			}
		}
		//
		/*for (int i = 0; i <= p_sz; ++i) {
			for (int j = 0; j <= s_sz; ++j) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/
		
		return dp[p_sz][s_sz];
	}
};

int main()
{
	Solution sol;
	string	s = "adceb",p = "*a*b";
	cout << sol.isMatch(s,p) << endl;
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
