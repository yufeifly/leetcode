// 17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Solution {
	vector<string> answer;
	string digit;
public:
	vector<string> letterCombinations(string digits) {
		digit = digits;
		if (digits.size() == 0) return answer;
		dfs("", 0);
		return answer;
	}

	void dfs(string s, int lev) {
		if (lev == (int)digit.size() - 1) {
			if (digit[lev] - '0' < 7) {
				answer.push_back(s + (char)((digit[lev] - '0' - 2) * 3 + 'a'));
				answer.push_back(s + (char)((digit[lev] - '0' - 2) * 3 + 'b'));
				answer.push_back(s + (char)((digit[lev] - '0' - 2) * 3 + 'c'));
			}
			else if (digit[lev] - '0' == 7) {
				answer.push_back(s + (char)(15 + 'a'));
				answer.push_back(s + (char)(15 + 'b'));
				answer.push_back(s + (char)(15 + 'c'));
				answer.push_back(s + (char)(15 + 'd'));
			}
			else if (digit[lev] - '0' == 8) {
				answer.push_back(s + (char)(19 + 'a'));
				answer.push_back(s + (char)(19 + 'b'));
				answer.push_back(s + (char)(19 + 'c'));
			}
			else if (digit[lev] - '0' == 9) {
				answer.push_back(s + (char)(22 + 'a'));
				answer.push_back(s + (char)(22 + 'b'));
				answer.push_back(s + (char)(22 + 'c'));
				answer.push_back(s + (char)(22 + 'd'));
			}
			
			return;
		}
		if (digit[lev] - '0' < 7) {
			dfs(s + (char)((digit[lev] - '0' - 2) * 3 + 'a'), lev + 1);
			dfs(s + (char)((digit[lev] - '0' - 2) * 3 + 'b'), lev + 1);
			dfs(s + (char)((digit[lev] - '0' - 2) * 3 + 'c'), lev + 1);
		}
		else if (digit[lev] - '0' == 7) {
			dfs(s + (char)(15 + 'a'), lev + 1);
			dfs(s + (char)(15 + 'b'), lev + 1);
			dfs(s + (char)(15 + 'c'), lev + 1);
			dfs(s + (char)(15 + 'd'), lev + 1);
		}
		else if (digit[lev] - '0' == 8) {
			dfs(s + (char)(19 + 'a'), lev + 1);
			dfs(s + (char)(19 + 'b'), lev + 1);
			dfs(s + (char)(19 + 'c'), lev + 1);
		}
		else if (digit[lev] - '0' == 9) {
			dfs(s + (char)(22 + 'a'), lev + 1);
			dfs(s + (char)(22 + 'b'), lev + 1);
			dfs(s + (char)(22 + 'c'), lev + 1);
			dfs(s + (char)(22 + 'd'), lev + 1);
		}
		dfs(s + (char)((digit[lev] - '0' - 2) * 3 + 'a'), lev + 1);
		dfs(s + (char)((digit[lev] - '0' - 2) * 3 + 'b'), lev + 1);
		dfs(s + (char)((digit[lev] - '0' - 2) * 3 + 'c'), lev + 1);
	}
};
int main()
{
	Solution sol;
	vector<string> answer = sol.letterCombinations("7");
	for (int i = 0; i < (int)answer.size(); ++i) {
		cout << answer[i] << endl;
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
