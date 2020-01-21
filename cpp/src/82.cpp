#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(head == NULL) return NULL;
		ListNode *newHead = new ListNode(head->val+1);
		newHead->next = head;
		ListNode *p = newHead;

		while(p->next) {
			ListNode *q = p->next;
			while(q && q->next && q->val == q->next->val) {
				q = q->next;
			}
			if(q != p->next) {
				// need del
				p->next = q->next;
			} else {
				p = q;
			}
		}
		return newHead->next;
	}
};

int main(){
	ListNode *head = new ListNode(1);
	ListNode *node2 = new ListNode(2); head->next = node2;
	ListNode *node3 = new ListNode(3); node2->next = node3;
	ListNode *node4 = new ListNode(3); node3->next = node4;
	ListNode *node5 = new ListNode(4); node4->next = node5;
	ListNode *node6 = new ListNode(4); node5->next = node6;
	ListNode *node7 = new ListNode(5); node6->next = node7;
	Solution sol;
	ListNode * answer = sol.deleteDuplicates(head);
	while(answer) {
		cout << answer->val << endl;
		answer = answer->next;
	}
	return 0;
}
