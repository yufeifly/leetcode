#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* newHead = reverseList(head->next);
		ListNode* newTail = newHead;
		if (newTail != NULL) {
			while (newTail->next != NULL) {
				newTail = newTail->next;
			}
		}
		if (newTail != NULL) newTail->next = head;
		head->next = NULL;
		return newHead;
	}
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* p = head;
		for (int i = 0; i < k-1; ++i) {
			if (p == NULL) return head;
			p = p->next;
		}
		if (p == NULL) return head;
		ListNode* q = p->next;
		p->next = NULL;
		ListNode *newHead = reverseList(head);
		ListNode *newList = reverseKGroup(q,k);
		ListNode* newp = newHead;
		while (newp->next != NULL) newp = newp->next;
		newp->next = newList;
		return newHead;
	}
};

int main()
{
	vector<int> vec = { 2,3,4,5,6,7,8 };
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	for (int i = 0; i < (int)vec.size(); ++i) {
		ListNode* tmp = new ListNode(vec[i]);
		p->next = tmp;
		p = p->next;
	}
	Solution sol;
	ListNode* answer = sol.reverseKGroup(head,3);
	while (answer != NULL) {
		cout << answer->val << endl;
		answer = answer->next;
	}

	return 0;
}
