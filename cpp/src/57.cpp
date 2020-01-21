// 57.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if ((int)intervals.size() == 0) {
			intervals.insert(intervals.begin(), newInterval);
		}
		int left = 0, right = 0;
		bool left_in = true, right_in = true;
		if (newInterval[1] < intervals[0][0]) {
			intervals.insert(intervals.begin(),newInterval);
			return intervals;
		}
		if (newInterval[0] > intervals[(int)intervals.size() - 1][1]) {
			intervals.insert(intervals.end(),newInterval);
			return intervals;
		}
		//
		for (int i = 0; i < (int)intervals.size(); ++i) {
			if (newInterval[0] <= intervals[i][1]) {
				left = i;
				if (newInterval[0] < intervals[i][0]) left_in = false;
				break;
			}
		}
		int i;
		for (i = left; i < (int)intervals.size(); ++i) {
			if (newInterval[1] <= intervals[i][1]) {
				right = i;
				if (newInterval[1] < intervals[i][0]) right_in = false;
				break;
			}
		}
		if (i == (int)intervals.size()) {
			vector<int> vec = { (intervals[left][0] > newInterval[0])? newInterval[0]: intervals[left][0],newInterval[1] };
			intervals.erase(intervals.begin() + left, intervals.end());
			intervals.insert(intervals.begin() + left, vec);
			return intervals;
		}
		//
		if (!left_in && !right_in) {
			if (left == right) {
				intervals.insert(intervals.begin() + left, newInterval);
			}
			else {
				intervals.erase(intervals.begin() + left, intervals.begin() + right);
				intervals.insert(intervals.begin()+ left,newInterval);
			}
		}
		else if (left_in && right_in) {
			if (left < right) {
				vector<int> vec = {intervals[left][0],intervals[right][1]};
				intervals.erase(intervals.begin() + left, intervals.begin() + right+1);
				intervals.insert(intervals.begin() + left, vec);
			}
		}
		else if (left_in && !right_in) {
			vector<int> vec = { intervals[left][0],newInterval[1] };
			intervals.erase(intervals.begin() + left, intervals.begin() + right);
			intervals.insert(intervals.begin() + left, vec);
		}
		else {
			vector<int> vec = { newInterval[0],intervals[right][1]};
			intervals.erase(intervals.begin() + left, intervals.begin() + right+1);
			intervals.insert(intervals.begin() + left, vec);
		}
		return intervals;

	}
};
int main()
{
	Solution sol;
	vector<vector<int>> vec1 = { {0,3} ,{4,6}, {8,10} };
	vector<int> vec2 = { 7,13 };
	vector<vector<int>> answer =  sol.insert(vec1,vec2);
	for (auto x : answer) {
		cout << x[0] << " " << x[1] << endl;
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
