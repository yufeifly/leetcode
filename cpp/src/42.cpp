// 42.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	int trap(vector<int>& height) {
//		int answer = 0;
//		int max_height = 0;
//		for (int i = 0; i < (int)height.size(); ++i) {
//			if (height[i] > max_height) max_height = height[i];
//		}
//		int left = 0,right = (int)height.size()-1;
//		for (int h = 1; h <= max_height; ++h) {
//			while (height[left] < h) ++left;
//			while (height[right] < h) --right;
//			if (right - left > 1) {
//				for (int i = left; i <= right; ++i) {
//					if (height[i] < h) answer += 1;
//				}
//			}
//		}
//		return answer;
//	}
//};

class Solution {
public:
	int trap(vector<int>& height) {
		int answer = 0;
		int sz = (int)height.size();
		for (int i = 1; i < sz - 1; ++i) {
			int left_max = 0, right_max = 0;
			for (int left = i; left >= 0; --left) {
				left_max = (left_max < height[left])?height[left] : left_max;
			}
			for (int right = i; right < sz; ++right) {
				right_max = (right_max < height[right])?height[right] : right_max;
			}
			answer += min(left_max,right_max) - height[i];
		}
		return answer;
	}
};
int main()
{
	Solution sol;
	vector<int> vec = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << sol.trap(vec) << endl;
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
