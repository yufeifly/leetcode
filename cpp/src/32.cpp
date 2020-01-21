// 32.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//private:
//	struct node {
//		char ch;
//		int order;
//		node(char c, int i){
//			ch = c;
//			order = i;
//		}
//	};
//	
//public:
//	static bool cmp(pair<int,int>&a, pair<int,int>&b) {
//		return a.first < b.first;
//	}
//	int longestValidParentheses(string s) {
//		if (s.size() == 0) return 0;
//		stack<node> st;
//		vector<pair<int,int> > vec;
//		vector<int>answer;
//		for (int i = 0; i < (int)s.size(); ++i) {
//			if (s[i] == '(') {
//				st.push(node(s[i], i));
//			}
//			else {
//				if (st.size() > 0) {
//					if (matched(st.top().ch,s[i])) {
//						if (st.size() == 1) {
//							vec.push_back(make_pair(st.top().order, i));
//							st.pop();
//						} else st.pop();
//					}
//				}
//			}
//		}
//		if (vec.size() == 0) return 0;
//		//sort
//		sort(vec.begin(), vec.end(), cmp);
//		//
//		int cur = vec[0].second - vec[0].first + 1;
//		for (int i = 0; i < (int)vec.size() - 1; ++i) {
//			if (vec[i].second + 1 == vec[i+1].first) {
//				cur += vec[i+1].second - vec[i + 1].first + 1;
//			}
//			else {
//				answer.push_back(cur);
//				cur = vec[i + 1].second - vec[i + 1].first + 1;
//			}
//		}
//		answer.push_back(cur);
//		int max = 0;
//		for (int i = 0; i < (int)answer.size(); ++i) {
//			if (max < answer[i]) max = answer[i];
//		}
//		/*for (auto i : vec) {
//			cout << i.first << " " << i.second << endl;
//		}*/
//		return max;
//	}
//
//	bool matched(char a, char b) {
//		if (a == '(' && b == ')') return true;
//		return false;
//	}
//};
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.length() == 0)
			return 0;
		int res = 0;
		stack<int> st;
		st.push(-1);
		for (int i = 0; i < (int)s.length(); ++i) {
			if (s[i] == '(') {
				st.push(i);
			}
			else {
				st.pop();
				if (!st.empty()) {
					res = max(res, i - st.top());
				}
				else {
					st.push(i);
				}
			}
		}

		return res;
	}

};

int main()
{
	Solution sol;
	cout << sol.longestValidParentheses(")())(()))") << endl;
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
