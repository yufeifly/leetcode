// 34.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> answer;
		int st = 0, ed = (int)nums.size() - 1;
		int mid;
		bool flag = false;
		while (st <= ed) {
			mid = (st + ed) / 2;
			if (nums[mid] == target) {
				flag = true;
				break;
			}
			else if (nums[mid] > target) {
				ed = mid - 1;
			}
			else {
				st = mid + 1;
			}
		}
		if (!flag) {
			return vector<int>{-1, -1};
		}
		for (int i = mid; i >= 0; --i) {
			if (nums[i] != target) {
				answer.push_back(i+1);
				break;
			}
			else if (i == 0) {
				answer.push_back(i);
			}
		}
		for (int i = mid; i < (int)nums.size(); ++i) {
			if (nums[i] != target) {
				answer.push_back(i-1);
				break;
			}
			else if (i == (int)nums.size() - 1) {
				answer.push_back(i);
			}
		}
		return answer;
	}
};
int main()
{
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	Solution sol;
	vector<int> answer = sol.searchRange(nums,8);
	for (auto s : answer) cout << s << endl;
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
