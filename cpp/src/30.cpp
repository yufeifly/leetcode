// 30.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include <vector>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		vector<int> answer;
//		if ((int)words.size() == 0) return answer;
//		int word_sz = (int)words[0].size(), word_num = (int)words.size();
//		int window = word_num * word_sz;
//		int s_sz = (int)s.size();
//		unordered_map<string, int> mp;
//		for (int i = 0; i < word_num; ++i) {
//			mp[words[i]] += 1;
//		}
//		for (int i = 0; i + window <= s_sz; ++i) {
//			unordered_map<string, int> mps;
//			string word = s.substr(i, window);
//			for (int j = 0; j < window; j += word_sz) {
//				mps[word.substr(j, word_sz)] += 1;
//			}
//			bool ok = true;
//			for (auto& x : mps) {
//				bool find = false;
//				for (auto& y : mp) {
//					if (x.first == y.first) {
//						find = (x.second == y.second) ? true : false;
//						break;
//					}
//				}
//				if (!find) {
//					ok = false;
//					break;
//				}
//			}
//			if (ok) answer.push_back(i);
//		}
//		return answer;
//	}
//};
//class Solution {
//public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		vector<int> answer;
//		if ((int)words.size() == 0) return answer;
//		int word_len = (int)words[0].size(), word_num = (int)words.size();
//		int window = word_num * word_len;
//		int s_sz = (int)s.size();
//		unordered_map<string, int> mp;
//		for (int i = 0; i < word_num; ++i) {
//			mp[words[i]] += 1;
//		}
//		for (int i = 0; i < word_len; ++i) {
//			int left = i, right = i;
//			int count = 0;
//			unordered_map<string, int> tmp_mp;
//			while (right + word_len - 1 < s_sz) {
//				string w = s.substr(right, word_len);
//				tmp_mp[w] += 1;
//				right += word_len;
//				++count;
//				while (tmp_mp[w] > mp[w]) {
//					string l_w = s.substr(left,word_len);
//					--count;
//					left += word_len;
//					tmp_mp[l_w] -= 1;
//				}
//				if (count == word_num) answer.push_back(left);
//			}
//		}
//		return answer;
//	}
//};
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> answer;
		if ((int)words.size() == 0) return answer;
		int word_len = (int)words[0].size(), word_num = (int)words.size();
		//int window = word_num * word_len;
		int s_sz = (int)s.size();
		unordered_map<string, int> mp;
		for (int i = 0; i < word_num; ++i) {
			mp[words[i]] += 1;
		}
		for (int i = 0; i < word_len; ++i) {
			int left = i, right = i;
			int count = 0;
			unordered_map<string, int> tmp_mp;
			while (right + word_len - 1 < s_sz) {
				string w = s.substr(right, word_len);
				tmp_mp[w] += 1;
				right += word_len;
				++count;
				if (mp[w] == 0) {
					count = 0;
					left = right;
					tmp_mp.clear();
				}
				else {
					while (tmp_mp[w] > mp[w]) {
						string l_w = s.substr(left, word_len);
						--count;
						left += word_len;
						tmp_mp[l_w] -= 1;
					}
				}
				if (count == word_num) answer.push_back(left);
			}
		}
		return answer;
	}
};
int main()
{
	Solution sol;
	string s = "wordgoodgoodgoodbestword";
	vector<string> vec = { "word","good","best","good" };
	vector<int> answer = sol.findSubstring(s,vec);
	for (auto s : answer) cout << s << endl;

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
