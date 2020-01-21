// 92.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
//class Solution {
//private:
//	ListNode* left;
//	bool stop;
//public:
//	ListNode* reverseBetween(ListNode* head, int m, int n) {
//		left = head;
//		stop = false;
//		reverse(head,m,n);
//		return head;
//	}
//	void reverse(ListNode* right, int m, int n) {
//		if (n == 1) return;
//		right = right->next;
//		if (m > 1) left = left->next;
//		reverse(right, m - 1, n - 1);
//		if (left == right || right->next == left) stop = true;
//		if (!stop) {
//			int tmp = left->val;
//			left->val = right->val;
//			right->val = tmp;
//			
//			left = left->next;
//		}
//	}
//};
class Solution {
private:
	ListNode* left;
	bool start;
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		left = head;
		start = false;
		reverse(head, m, n);
		return head;
	}
	void reverse(ListNode* right, int m, int n) {
		if (n <= 0) return;
		else if (n == 1) start = true;
		if (m > 1) left = left->next;
		reverse(right->next, m - 1, n - 1);
		if (left == right || right->next == left) start = false;
		if (start) {
			swap(left->val,right->val);
			left = left->next;
		}
		
	}
};

ListNode* list_add_tail(ListNode *head, ListNode *newnode) {
	if (!head) head = newnode;
	else {
		ListNode* p = head;
		while (p->next) p = p->next;
		p->next = newnode;
	}
	return head;
}

int main()
{
	Solution sol;
	vector<int> vec = { 1,2,3,4};
	ListNode* head = NULL;
	for (int i = 0; i < (int)vec.size(); ++i) {
		ListNode* newnode = new ListNode(vec[i]);
		head = list_add_tail(head,newnode);
	}
	ListNode* answer = sol.reverseBetween(head,1,4);
	while (answer) {
		cout << answer->val << " ";
		answer = answer->next;
	}
	cout << endl;
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
