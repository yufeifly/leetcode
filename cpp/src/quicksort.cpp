// quicksort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Quicksort {
public:
	void Qsort(vector<int>& nums,int left,int right) {
		if ((int)nums.size() <= 0) return;
		int pivot = nums[left];
		if (left >= right) return;
		int i = left, j = right;
		while (i < j) {
			while (i < j && nums[j] >= pivot) --j;
			if(j > i) nums[i] = nums[j];
			while (i < j && nums[i] <= pivot) ++i;
			if (i < j) nums[j] = nums[i];
		}
		nums[i] = pivot;
		Qsort(nums,left,i-1);
		Qsort(nums, i + 1, right);
	}
};

int main()
{
	vector<int>vec = {3,2,1,5,7};
	Quicksort qs;
	qs.Qsort(vec, 0, (int)vec.size() - 1);
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
