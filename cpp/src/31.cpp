// 31.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if ((int)nums.size() == 1) return;
		int val = nums[(int)nums.size()-1];
		int i = (int)nums.size() - 2;
		while (nums[i] >= val) {
			val = nums[i];
			--i;
			if (i < 0) {
				//reverse
				reverse(nums.begin(),nums.end());
				return;
			}
		}
		//
		for (int j = (int)nums.size() - 1; j > i; --j) {
			if (nums[j] > nums[i]) {
				int plate = nums[i];
				nums[i] = nums[j];
				nums[j] = plate;
				break;
			}
		}
		//
		sort(nums.begin() + i + 1, nums.end());
	}
};

int main()
{
	Solution sol;
	vector<int> vec = { 5,1,1 };
	sol.nextPermutation(vec);
	for (auto s : vec) cout << s << endl;
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
