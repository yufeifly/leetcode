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
			ListNode *p = head,*q = NULL;
			if(head == NULL) return head;
			while(p->next) {
				q = p->next;
				while(q->val == p->val) {
					p->next = q->next;
					delete(q);
					q = p->next;
					if(q == NULL) break;
				}
				p = p->next;
				if(p == NULL) break;
			}
			return head;
			    
		}
		
};

int main(){
	Solution sol;
	ListNode *head = new ListNode(1);
	ListNode *node2 = new ListNode(1); head->next = node2;
	ListNode *node3 = new ListNode(2); node2->next = node3;
	ListNode *node4 = new ListNode(3); node3->next = node4;
	ListNode *node5 = new ListNode(3); node4->next = node5;

	ListNode * answer = sol.deleteDuplicates(head);
	while(answer) {
		cout << answer->val << endl;
		answer = answer->next;
	}
	return 0;
}
