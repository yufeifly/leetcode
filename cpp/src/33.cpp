// 33.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		//int peak = 0;
		int st = 0, ed = (int)nums.size()-1;
		while (st <= ed) {
			int mid = (st + ed) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (target < nums[0]) {
				if (nums[mid] >= nums[0]) {
					st = mid + 1;
				}
				else {
					if (nums[mid] > target) ed = mid - 1;
					else if (nums[mid] < target) st = mid + 1;
				}
			}
			else {
				if (nums[mid] < nums[0]) {
					ed = mid - 1;
				}
				else {
					if (nums[mid] > target) ed = mid - 1;
					else if (nums[mid] < target) st = mid + 1;
				}
			}
		}
		return -1;
	}
};
int main()
{
	Solution sol;
	vector<int> vec = { 4,5,6,7,0,1,2 };
	cout << sol.search(vec, 0) << endl;
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
