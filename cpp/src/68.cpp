// 68.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxW;
	string makeString(int head, int tail, vector<string>& words) {
		string s = "";
		if (head == tail) {
			if((int)words[head].size() == maxW) return words[head];
			string vacancy(maxW-(int)words[head].size(), ' ');
			return words[head] + vacancy;
		}
		int pure_ch = 0;
		for (int i = head; i <= tail; ++i) pure_ch += (int)words[i].size();
		if (tail == (int)words.size() - 1) {
			s += words[head];
			for (int i = head + 1; i <= tail; ++i) {
				s += ' ' + words[i];
			}
			string vacancy(maxW - (int)s.size(), ' ');
			s += vacancy;
			return s;
		}
		int avg = (maxW - pure_ch) / (tail - head);
		int remainder = (maxW - pure_ch) % (tail - head);
		s += words[head];
		string vacancy(avg, ' ');
		for (int i = head + 1; i <= tail; ++i) {
			s += ((i-head-1<remainder)?(vacancy+' '):vacancy) + words[i];
		}
		return s;
	}
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		maxW = maxWidth;
		vector<string> answer;
		int word_num = (int)words.size();
		int head = 0,tail = 0;
		int sum_ch = 0;
		while (tail < word_num) {
			int add_ch = (int)words[tail].size() + ((head == tail) ? 0 : 1);
			if (sum_ch + add_ch > maxWidth) {
				// 知道了头和尾: head = head, tial = tail -1 ,make a string
				answer.push_back(makeString(head, tail-1, words));
				head = tail;
				sum_ch = 0;
			}
			else {
				if (tail == word_num - 1) {//到了最后一个
					answer.push_back(makeString(head, tail, words));
					++tail;
				}
				else {
					++tail;
					sum_ch += add_ch;
				}
			}
		}
		return answer;
	}
};
int main()
{
	vector<string> vec = { "What","must","be","acknowledgment","shall","be" };
	Solution sol;
	vector<string> answer = sol.fullJustify(vec,16);
	for (auto s : answer) {
		cout << s << endl;
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
