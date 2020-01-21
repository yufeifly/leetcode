// 76.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;


//超时了
//class Solution {
//private:
//	map<char, int> mpT;
//	set<char> seT;
//	bool map_equal(map<char, int>& mp) {
//		for (auto elem : seT) {
//			if (mpT[elem] > mp[elem]) return false;
//		}
//		return true;
//	}
//public:
//	string minWindow(string s, string t) {
//		int minV = INT_MAX, start = -1, end = -1;
//		vector<int> index;
//		for (int i = 0; i < (int)t.size(); ++i) {
//			mpT[t[i]] += 1;
//			seT.insert(t[i]);
//		}
//		int mpT_sz = (int)mpT.size();
//		for (int i = 0; i < (int)s.size(); ++i) {
//			if (mpT[s[i]] > 0) index.push_back(i);
//		}
//		for (int i = 0; i < (int)index.size(); ++i) {
//			map<char, int> mp;
//			int j = i;
//			while (j < (int)index.size()) {
//				mp[s[index[j]]] += 1;
//				if (j - i + 1 < mpT_sz) {
//					++j;
//					continue;
//				}
//				if (map_equal(mp)) {
//					int val = index[j] - index[i] + 1;
//					if (minV > index[j] - index[i] + 1) {
//						minV = val;
//						start = index[i]; end = index[j];
//					}
//					break;
//				}
//				++j;
//			}
//		}
//		if (start == -1 && end == -1) return "";
//		return s.substr(start,end-start+1);;
//	}
//};
class Solution {
public:
	string minWindow(string s, string t) {
		int minV = INT_MAX, start = -1, end = -1;
		unordered_map<char, int> mapT;
		unordered_map<char, int> mapS;
		queue<int>que;
		for (int i = 0; i < (int)t.size(); ++i) {
			mapT[t[i]] += 1;
		}
		int required = (int)mapT.size();
		int owned = 0;
		int left = 0, right = 0;
		for (; right < (int)s.size(); ++right) {
			char ch = s[right];
			// 如果ch是t中的字符
			if (mapT[ch] > 0) { 
				mapS[ch] += 1;	
				que.push(right);
				if (mapS[ch] == mapT[ch]) {
					owned += 1;
				}
				while (!que.empty() && owned == required) {
					left = que.front();
					que.pop();
					char c = s[left];
					int val = right - left + 1;
					if (minV > val) {
						minV = val;
						start = left; 
						end = right;
					}
					mapS[c] -= 1;
					if (mapS[c] < mapT[c]) owned -= 1;
				}
			}
			
		}
		if (start == -1 && end == -1) return "";
		return s.substr(start, end - start + 1);;
	}
};
int main()
{
	Solution sol;
	cout << sol.minWindow("ADOBECODEBANC","ABC") << endl;
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
