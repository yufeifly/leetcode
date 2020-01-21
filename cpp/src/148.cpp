// 148.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* Linsert(ListNode* head, ListNode* elem) {
		if (head == NULL) head = elem;
		else {
			elem->next = head->next;
			head->next = elem;
		}
		return head;
	}
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* left = NULL, * right = NULL;
		ListNode* p = head->next;
		while (p) {
			ListNode* q = p->next;
			p->next = NULL;
			if (p->val > head->val) {
				
				right = Linsert(right, p);
			}
			else {
				left = Linsert(left, p);
			}
			p = q;
		}
		right = sortList(right);
		left = sortList(left);
		//
		head->next = right;
		if (left) {
			ListNode* q = left;
			while (q->next) q = q->next;
			q->next = head;
			head = left;
		}
		return head;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 0,4,3,5 };
	ListNode* head = new ListNode(-1);
	for (auto s : nums) {
		ListNode* p = new ListNode(s);
		sol.Linsert(head, p);
	}
	head = sol.sortList(head);
	while (head) {
		cout << head->val << endl;
		head = head->next;
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
