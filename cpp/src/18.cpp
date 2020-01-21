// 18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int> > answer;
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(),nums.end());
		for (int i = 0; i < (int)nums.size()-3; ++i) {
			if (i != 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			for (int j = i + 1; j < (int)nums.size(); ++j) {
				if (j != i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				int left = j + 1, right = (int)nums.size()-1;
				while (left < right) {
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if ((left != j + 1 && nums[left] == nums[left - 1]) || sum < target) {
						++left;
					}
					else if ((right != (int)nums.size() - 1 && nums[right] == nums[right + 1]) || sum > target) {
						--right;
					}
					else if(sum == target){
						answer.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						++left;
						--right;
					}

				}
			}
		}
		return answer;
	}
};

int main()
{
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	Solution sol;
	vector<vector<int> > answer = sol.fourSum(nums,0);
	for (int i = 0; i < (int)answer.size(); ++i) {
		for (int j = 0; j < (int)answer[i].size(); ++j) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
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
