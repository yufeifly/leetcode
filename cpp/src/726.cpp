// 726.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

class Solution {
private:
	bool upcase(char c) {
		return (c >= 'A' && c <= 'Z');
	}
	bool lowcase(char c) {
		return (c >= 'a' && c <= 'z');
	}
	bool isdigit(char c) {
		return (c >= '0' && c <= '9');
	}
	int str2int(string s) {
		int pow = 1;
		int answer = 0;
		for (int i = (int)s.size() - 1; i >= 0; --i) {
			answer += (s[i] - '0') * pow;
			pow *= 10;
		}
		return answer;
	}
public:
	string countOfAtoms(string formula) {
		string answer = "";
		map<string, int> mp;
		count(formula,0,mp);
		for (map<string, int>::iterator i = mp.begin(); i != mp.end(); i++) {
			answer += i->first + ((i->second > 1)? to_string(i->second) : "");
		}
		return answer;
	}
	int count(string &formula,int st, map<string,int>&mp) {
		//map<string, int> mp;
		// 
		int i;
		for (i = st; i < (int)formula.size();) {
			// 如果是大写字母
			if (upcase(formula[i])) {
				int j = i + 1;
				while (j < (int)formula.size() && (lowcase(formula[j]) || isdigit(formula[j])))
					++j;
				int index = -1;
				for (int k = i+1; k <= j-1; ++k) {
					if (isdigit(formula[k])) {
						index = k; break;
					}
				}
				if (index == -1) mp[formula.substr(i, j - i)] += 1;
				else mp[formula.substr(i,index-i)] += str2int(formula.substr(index,j-index));
				//
				i = j;
			}
			else if(formula[i] == '('){
				map<string, int> tmp;
				int next_i = count(formula,i+1,tmp);
				i = next_i + 1;
				while (isdigit(formula[i])) ++i;
				int pow = 1;
				if (i > next_i+1) {
					pow = str2int(formula.substr(next_i+1,i - next_i-1));
				}
				for (auto& x : tmp) {
					mp[x.first] += x.second * pow;
				}
			}
			else if (formula[i] == ')') {
				break;
			}
		}
		return i;
	}
};

class Solution2 {
private:
	bool upcase(char c) {
		return (c >= 'A' && c <= 'Z');
	}
	bool lowcase(char c) {
		return (c >= 'a' && c <= 'z');
	}
	bool isdigit(char c) {
		return (c >= '0' && c <= '9');
	}
	int str2int(string s) {
		int pow = 1;
		int answer = 0;
		for (int i = (int)s.size() - 1; i >= 0; --i) {
			answer += (s[i] - '0') * pow;
			pow *= 10;
		}
		return answer;
	}
	map<int, int>match;
public:
	string countOfAtoms(string formula) {
		string answer = "";
		map<string, int> mp;
		stack<int> stk;
		//
		for (int i = 0; i < (int)formula.size(); ++i) {
			if (formula[i] == '(') stk.push(i);
			else if (formula[i] == ')') {
				match[stk.top()] = i;
				stk.pop();
			}
		}
		//
		count(formula, 0, mp);
		for (map<string, int>::iterator i = mp.begin(); i != mp.end(); i++) {
			answer += i->first + ((i->second > 1) ? to_string(i->second) : "");
		}
		return answer;
	}
	void count(string& formula, int st, map<string, int>& mp) {
		for (int i = st; i < (int)formula.size();) {
			if (formula[i] == '(') {
				map<string, int> tmp;
				count(formula, i + 1, tmp);
				int j = match[i] + 1;
				while (j < (int)formula.size() && isdigit(formula[j])) ++j;
				int pow = 1;
				if (j > match[i] + 1) pow = str2int(formula.substr(match[i] + 1, j - match[i] - 1));
				for (auto& x : tmp) {
					mp[x.first] += x.second * pow;
				}
				i = j;
			}
			else if (upcase(formula[i])) {
				int j = i + 1;
				while (j < (int)formula.size() && lowcase(formula[j])) ++j;
				string name = formula.substr(i, j - i);
				int k = j;
				while (k < (int)formula.size() && isdigit(formula[k])) ++k;
				if (isdigit(formula[k - 1])) {
					mp[name] += str2int(formula.substr(j, k - j));
				}
				else mp[name] += 1;
				i = k;
			}
			else break;
		}
	}
};
int main()
{
	Solution sol;
	Solution2 sol2;
	cout << sol.countOfAtoms("K4((ON)2(SO3)2)2") << endl;
	cout << sol2.countOfAtoms("K4((ON)2(SO3)2)2") << endl;
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
