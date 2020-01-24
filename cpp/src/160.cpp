#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
 		ListNode *p1 = headA, *p2 = headB;
		ListNode *tail1 = headA, *tail2 = headB;
		if(p1 == NULL || p2 == NULL) return NULL;
		while(tail1->next != NULL) {
			tail1 = tail1->next;
		}
		while(tail2->next != NULL) {
			tail2 = tail2->next;
		}
		while(true) {
			if(p1 == p2) return p1;
			if(p1 == tail2 && p2 == tail1) return NULL;
			if(p1 == tail1) p1 = headB;
			else p1 = p1->next;
			if(p2 == tail2) p2 = headA;
			else p2 = p2->next;
		}
		return NULL;
    }
};

int main() {
	ListNode *head1 = new ListNode(4);
	ListNode *node[4] = {NULL};
	node[0] = new ListNode(1);
	node[1] = new ListNode(8);
	node[2] = new ListNode(4);
	node[3] = new ListNode(5);
	ListNode *p1 = head1;
	for(int i=0;i<4;++i) {
		p1->next = node[i];
		p1 = p1->next;
	}
	ListNode *head2 = new ListNode(5);
	ListNode *tmp1 = new ListNode(0);
	ListNode *tmp2 = new ListNode(1);
	head2->next = tmp1;
	tmp1->next = tmp2;
	tmp2->next = node[1];

	Solution sol;
	ListNode *answer = sol.getIntersectionNode(NULL,NULL);
	if (answer != NULL)
		cout << answer->val << endl;
	return 0;
}
