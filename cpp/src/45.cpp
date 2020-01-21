// 45.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int sz = (int)nums.size();
		if (sz == 0 || sz == 1) return 0;
		int answer = 0;
		int left = 0, right = 0;
		while (left < sz - 1 && right < sz - 1) {
			int max_right = -1;
			for (int i = left; i <= right; ++i) {
				if (i + nums[i] > max_right) max_right = i + nums[i];
			}
			left = right + 1;
			right = max_right;
			answer += 1;
		}
		return answer;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 2,3,1,1,4 };
	cout << sol.jump(nums) << endl;
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
