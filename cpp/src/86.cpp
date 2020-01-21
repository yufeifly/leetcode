// 86.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* bigHead = NULL;
		ListNode* newHead = new ListNode(0);
		newHead->next = head;
		ListNode* p = newHead;
		while (p->next) {
			if (p->next->val >= x) {
				ListNode* q = p->next;
				p->next = p->next->next;
				q->next = NULL;
				bigHead = list_add_tail(bigHead,q);
			}
			else p = p->next;
		}

		p->next = bigHead;
		return newHead->next;
	}
	ListNode* list_add_tail(ListNode* head, ListNode* newnode) {
		if (!head) head = newnode;
		else {
			ListNode* p = head;
			while (p->next) p = p->next;
			p->next = newnode;
		}
		return head;
	}
};

ListNode* list_add_tail(ListNode* head, ListNode* newnode) {
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
	vector<int> vec = {1,4,3,2,5,2};
	ListNode *head = NULL;
	for (int i = 0; i < (int)vec.size(); ++i) {
		ListNode* node = new ListNode(vec[i]);
		head = list_add_tail(head, node);
	}
	Solution sol;
	ListNode *answer = sol.partition(head, 3);
	while (answer) {
		cout << answer->val << " ";
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
