// 72.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int word1_sz = (int)word1.size();
		int word2_sz = (int)word2.size();
		vector<vector<int>> dp(word1_sz+1,vector<int>(word2_sz+1));
		for (int i = 0; i < word2_sz + 1; ++i) {
			dp[0][i] = i;
		}
		for (int i = 0; i < word1_sz + 1; ++i) {
			dp[i][0] = i;
		}
		for (int i = 1; i < word1_sz + 1; ++i) {
			for (int j = 1; j < word2_sz + 1; ++j) {
				if (word1[i-1] == word2[j-1]) {
					dp[i][j] = dp[i-1][j-1];
				}
				else {
					dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i-1][j],dp[i][j-1]));
				}
			}
		}
		return dp[word1_sz][word2_sz];
	}
};

int main()
{
	Solution sol;
	cout << sol.minDistance("horse", "ros") << endl;
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
