// 12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
	string getC(int pow) {
		switch (pow)
		{
		case 0: return "M";
		case 1: return "C";
		case 2: return "X";
		case 3: return "I";
		default:break;
		}
		return "";
	}
	string transform(int number, int pow) {
		if (number == 0) return "";
		string answer = "";
		if (number == 9 || number == 4) {
			switch (pow)
			{
			case 1: return (number == 9) ? "CM" : "CD";
			case 2: return (number == 9) ? "XC" : "XL";
			case 3: return (number == 9) ? "IX" : "IV";
			default:break;
			}
		}
		else if (number >= 1 && number <= 3) {
			string str = getC(pow);
			for (int i = 0; i < number; ++i) {
				answer.append(str);
			}
		}
		else {
			switch (pow)
			{
			case 1:answer.append("D"); break;
			case 2:answer.append("L"); break;
			case 3:answer.append("V"); break;
			default:break;
			}
			string str = getC(pow);
			for (int i = 5; i < number; ++i) {
				answer.append(str);
			}
		}
		return answer;
	}

public:
	string intToRoman(int num) {
		string answer = "";
		int arr[4];
		for (int i = 0; i < 4; ++i) arr[i] = 0;
		int i = 3;
		while (num > 0)
		{
			int remainder = num % 10;
			arr[i] = remainder;
			--i;
			num /= 10;
		}
		for (int i = 0; i < 4; ++i) {
			answer += transform(arr[i], i);	
		}
		return answer;
	}
};

int main()
{
	Solution sol;
	cout << sol.intToRoman(58) << endl;
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
