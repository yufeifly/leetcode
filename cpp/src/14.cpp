// 14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if ((int)strs.size() < 1) return "";
		if ((int)strs.size() == 1) return strs[0];
		int cur = 0;
		while (cur < (int)strs[0].size())
		{
			bool finish = false;
			char ch = strs[0][cur];
			for (int i = 1; i < (int)strs.size(); ++i) {
				if (cur >= (int)strs[i].size() || ch != strs[i][cur]) {
					finish = true;
					break;
				}
			}
			if (finish) {
				break;
			}
			++cur;
		}
		return strs[0].substr(0,cur);
	}
};

int main()
{
	Solution sol;
	vector<string> vec = { "flower","flow","flight" };
	cout << sol.longestCommonPrefix(vec) << endl;
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
