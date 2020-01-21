// 43.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	string my_mul(string s, char c) {
		string answer = "";
		int carry = 0;
		int cint = c - '0';
		for (int i = (int)s.size()-1; i >= 0; --i) {
			int tmp = (s[i]-'0') * cint + carry;
			carry = tmp / 10;
			answer += (tmp % 10 + '0');
		}
		if (carry > 0) answer += (carry + '0');
		return answer;
	}
	string add_string(string a,string b) {
		string answer = "";
		int i = 0;
		int carry = 0;
		while (i < (int)a.size() && i < (int)b.size()) {
			int tmp = (a[i] - '0') + (b[i] - '0') + carry;
			carry = tmp / 10;
			answer += (tmp % 10 + '0');
			++i;
		}
		if (i == (int)a.size()) {
			while (i < (int)b.size()) {
				int tmp = (b[i]-'0') + carry;
				carry = tmp / 10;
				answer += (tmp % 10 + '0');
				++i;
			}
		}
		else {
			while (i < (int)a.size()) {
				int tmp = (a[i]-'0') + carry;
				carry = tmp / 10;
				answer += (tmp % 10 + '0');
				++i;
			}
		}
		if (carry > 0) answer += (carry + '0');
		return answer;
	}
	string multiply(string num1, string num2) {
		string answer = "0";
		int nums2_sz = (int)num2.size();
		for (int i = nums2_sz - 1; i >= 0; --i) {
			string tmp = my_mul(num1, num2[i]);
			string zero(nums2_sz - 1 - i,'0');
			tmp = zero + tmp;
			answer = add_string(tmp,answer);
			//cout << tmp << endl << answer << endl;
		}
		int i = (int)answer.size() -1;
		while (i > 0) {
			if (answer[i] == '0') { 
				answer.pop_back(); 
				--i;
			}
			else break;
		}

		reverse(answer.begin(),answer.end());
		return answer;
	}
};

class Solution2 {
public:
	string multiply(string num1, string num2) {
		int n1 = num1.size();
		int n2 = num2.size();
		string res(n1 + n2, '0');
		for (int i = n2 - 1; i >= 0; i--) {
			for (int j = n1 - 1; j >= 0; j--) {
				int temp = (res[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
				res[i + j + 1] = temp % 10 + '0';//当前位
				res[i + j] += temp / 10; //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
			}
		}

		//去除首位'0'
		for (int i = 0; i < n1 + n2; i++) {
			if (res[i] != '0')
				return res.substr(i);
		}
		return "0";


	}
};
int main()
{
	Solution sol;
	Solution2 sol2;
	string s1 = "123456789", s2 = "987654321";
	string answer1 = sol.multiply(s1,s2);
	string answer2 = sol2.multiply(s1, s2);
	cout << endl;
	if (answer1 == answer2) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
		cout << answer1 << endl << answer2 << endl;
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
