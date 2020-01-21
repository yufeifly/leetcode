// 21.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
//class Solution {
//private:
//	ListNode* insertL(ListNode* head, ListNode* node) {
//		if (head == NULL) {
//			head = node;
//		}
//		else {
//			ListNode* p = head;
//			while (p->next != NULL) p = p->next;
//			p->next = node;
//		}
//		return head;
//	}
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		ListNode* p = l1, *q = l2;
//		ListNode* head = NULL;
//		while (p != NULL && q != NULL) {
//			if (p->val < q->val) {
//				ListNode* tmp = p;
//				p = p->next;
//				tmp->next = NULL;
//				head = insertL(head,tmp);
//			}
//			else {
//				ListNode* tmp = q;
//				q = q->next;
//				tmp->next = NULL;
//				head = insertL(head, tmp);
//			}
//		}
//		if (p != NULL) {
//			head = insertL(head, p);
//		}
//		if (q != NULL) {
//			head = insertL(head, q);
//		}
//		return head;
//	}
//};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next,l2);
			return l1;
		} 
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
		return NULL;
	}
};

void insertL(ListNode* head, ListNode* node) {
	ListNode* p = head;
	if (p == NULL) {
		p = node;
	}
	else {
		while (p->next != NULL) p = p->next;
		p->next = node;
	}
}
int main()
{
	ListNode* p1 = new ListNode(1);
	vector<int> vec1 = { 2,4 };
	for (int i = 0; i < (int)vec1.size(); ++i) {
		ListNode* tmp = new ListNode(vec1[i]);
		insertL(p1, tmp);
	}
	ListNode* p2 = new ListNode(1);
	vector<int> vec2 = { 3,4 };
	for (int i = 0; i < (int)vec2.size(); ++i) {
		ListNode* tmp = new ListNode(vec2[i]);
		insertL(p2, tmp);
	}
	Solution sol;
	ListNode * answer = sol.mergeTwoLists(p1, p2);
	while (answer != NULL) {
		cout << answer->val << endl;
		answer = answer->next;
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
