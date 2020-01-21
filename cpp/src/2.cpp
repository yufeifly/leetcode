#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1, * p2 = l2;
		ListNode* pHead = new ListNode(0);
		ListNode* pTail = pHead;
		int carry = 0;
		while (p1 != NULL && p2 != NULL)
		{
			int tmp = (p1->val + p2->val + carry) % 10;
			carry = (p1->val + p2->val + carry) / 10;
			pTail->next = new ListNode(tmp);
			pTail = pTail->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		while (p1 != NULL) {
			int tmp = (p1->val + carry) % 10;
			carry = (p1->val + carry) / 10;
			pTail->next = new ListNode(tmp);
			pTail = pTail->next;
			p1 = p1->next;
		}
		while (p2 != NULL) {
			int tmp = (p2->val + carry) % 10;
			carry = (p2->val + carry) / 10;
			pTail->next = new ListNode(tmp);
			pTail = pTail->next;
			p2 = p2->next;
		}
		if (carry != 0) {
			pTail->next = new ListNode(carry);
		}
		ListNode* p = pHead->next;
		delete pHead;
		return p;
	}
};

int main() {
	ListNode* l1 = new ListNode(1), * l2 = l1;
	l2->next = new ListNode(8); l2 = l2->next;

	ListNode* s1 = new ListNode(0);
	//ListNode * s2 = s1;
	/*s2->next = new ListNode(6); s2 = s2->next;
	s2->next = new ListNode(4); s2 = s2->next;*/
	Solution s;
	ListNode* p = s.addTwoNumbers(l1, s1);
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}
