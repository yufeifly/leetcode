// 7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <limits.h>
#include <stack>
using namespace std;
//class Solution {
//public:
//	int reverse(int x) {
//		int rev = 0;
//		while (x != 0) {
//			int pop = x % 10;
//			x /= 10;
//			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
//			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
//			rev = rev * 10 + pop;
//		}
//		return rev;
//	}
//};
class Solution {
public:
	int reverse(int x) {
		if (x <= INT_MIN || x > INT_MAX) return 0;
		int answer = 0;
		stack<int> st;
		bool sign = true;
		if (x < 0) {
			sign = false;
			x = -x;
		}
		while (x > 0) {
			st.push(x % 10);
			x /= 10;
		}
		int pow = 1;
		while (!st.empty()) {
			int dig = st.top();
			answer += dig * pow;
			if (answer > INT_MAX) return 0;
			st.pop();
			pow *= 10;
		}
		return (sign == true)? answer : -answer;
	}
};

int main()
{
	Solution sol;
	cout << sol.reverse(-2147483648) << endl;
	//cout << -123 % 10 << endl;
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
