// 29.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		long long lldividend = (long long)dividend;
		long long lldivisor = (long long)divisor;
		if (abs(lldividend) < abs(lldivisor)) return 0;
		bool sign = true;
		if ((lldividend > 0 && lldivisor < 0) || (lldividend < 0 && lldivisor > 0)) sign = false;
		lldividend = (lldividend > 0) ? lldividend : -lldividend;
		lldivisor = (lldivisor > 0) ? lldivisor : -lldivisor;
		long long answer = 0;
		while (true) {
			int cur_bit = 0;
			while ((lldivisor << cur_bit) <= lldividend) {
				cur_bit += 1;
			}
			cur_bit -= 1;
			answer += ((long long)1 << cur_bit);
			lldividend -= (lldivisor << cur_bit);
			if (lldividend < lldivisor) {
				break;
			}
		}
		return (sign)? (int)answer: -(int)answer;
	}
};

int main()
{
	Solution sol;
	cout << sol.divide(INT_MIN,1) << endl;
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
