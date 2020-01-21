#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * initList(vector<int>vec) {
	if((int)vec.size() <= 0) return NULL;
	ListNode *head = new ListNode(vec[0]);
	for(int i=1;i<(int)vec.size();++i) {
		ListNode *node = new ListNode(vec[i]);
		ListNode *p = head;
		while(p->next) p = p->next;
		p->next = node;
	}
	return head;
}

class Solution {
	public:
		ListNode* sortList(ListNode* head) {
			if(head == NULL || head->next == NULL) return head;
			ListNode *fast = head->next,*slow = head;
			while(fast && fast->next) {
				fast = fast->next->next;
				slow = slow->next;
			}
			ListNode *mid = slow->next;
			slow->next = NULL;
			ListNode *left = sortList(head);
			ListNode *right = sortList(mid);
			ListNode *newhead = new ListNode(0);
			ListNode *newp = newhead;
			while(left && right) {
				if(left->val > right->val) {
					newp->next = right;
					right = right->next;
				} else {
					newp->next = left;
					left = left->next;
				}
				newp = newp->next;
			}
			newp->next = (left)?left:right;
			return newhead->next;
		}
};

int main(){
	vector<int>vec = {4,2,1,3};
	ListNode *head = initList(vec);
	//	ListNode *p = head;
	Solution sol;
	ListNode *answer = sol.sortList(head);
	while(answer) {
		cout << answer->val << endl;
		answer = answer->next;
	}
	return 0;
}
