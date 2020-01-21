// 97.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Solution { //超时
//private:
//	string str1, str2, str3;
//	int str1_sz, str2_sz, str3_sz;
//	bool interleave(int p1, int p2, int p3) {
//		if (p3 == str3_sz) return true;
//		if (p1 == str1_sz) return str2.substr(p2) == str3.substr(p3);
//		if (p2 == str2_sz) return str1.substr(p1) == str3.substr(p3);
//		if (str1[p1] == str3[p3] && str2[p2] != str3[p3]) return interleave(p1+1,p2,p3+1);
//		if (str1[p1] != str3[p3] && str2[p2] == str3[p3]) return interleave(p1, p2+1, p3+1);
//		if(str1[p1] == str3[p3] && str2[p2] == str3[p3]) return interleave(p1 + 1, p2, p3 + 1) || interleave(p1, p2 + 1, p3 + 1);
//		if (str1[p1] != str3[p3] && str2[p2] != str3[p3]) return false;
//		return true;
//	}
//public:
//	bool isInterleave(string s1, string s2, string s3) {
//		str1 = s1; str1_sz = (int)s1.size();
//		str2 = s2; str2_sz = (int)s2.size();
//		str3 = s3; str3_sz = (int)s3.size();
//		if (str1_sz + str2_sz != str3_sz) return false;
//		return interleave(0,0,0);
//	}
//};

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int s1_sz = (int)s1.size(), s2_sz = (int)s2.size();
		if (s1_sz + s2_sz != (int)s3.size()) return false;
		if (s1_sz == 0) return s2 == s3;
		if (s2_sz == 0) return s1 == s3;
		vector<vector<bool>> vec(s2_sz+1,vector<bool>(s1_sz+1,0));
		vec[0][0] = 1;
		bool flag = true;
		for (int i = 0; i < s1_sz; ++i) {
			if (flag) {
				if (s1[i] == s3[i]) {
					vec[0][i + 1] = 1;	
				}
				else {
					vec[0][i + 1] = 0;
					flag = false;
				}
			}
			else vec[0][i + 1] = 0;
		}
		flag = true;
		for (int i = 0; i < s2_sz; ++i) {
			if (flag) {
				if (s2[i] == s3[i]) {
					vec[i+1][0] = 1;
				}
				else {
					vec[i+1][0] = 0;
					flag = false;
				}
			}
			else vec[i+1][0] = 0;
		}
		//
		for (int i = 0; i < s2_sz; ++i) {
			for (int j = 0; j < s1_sz; ++j) {
				vec[i + 1][j + 1] = 0;
				if ((vec[i][j + 1] && s3[i + j + 1] == s2[i]) || (vec[i + 1][j] && s3[i + j + 1] == s1[j])) 
					vec[i + 1][j + 1] = 1;
			}
		}
		return vec[s2_sz][s1_sz];
	}
};

int main()
{
	Solution sol;
	cout << sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
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
