#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* insert(ListNode *head, ListNode ** prev, ListNode *node) {
		if(node->val >= (*prev)->val) {
			(*prev) = node;
			return head;
		}
		(*prev)->next = node->next;

		if(node->val < head->val) {
			node->next = head;
			head = node;
		} else {
			// 找到合适的位置
			ListNode *p = head;
			while(p->next != *prev) {
				if(p->val <= node->val && p->next->val >= node->val) {
					break;
				}
				p = p->next;
			}
			node->next = p->next;
			p->next = node;

		}
		return head;
	}
public:
	ListNode* insertionSortList(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode *p = head;
		while(p->next) {
			head = insert(head,&p,p->next);
			//p = p->next;
		}
		return head;
	}
};


int main() {
	Solution sol;
	ListNode *head = new ListNode(-1);
	int vec[] = {5,3,4,0};
	for(int i=0;i<4;++i) {
		ListNode *node = new ListNode(vec[i]);
		ListNode *p = head;
		while(p->next) p = p->next;
		p->next = node;
	}
//	ListNode * ptr = head;
//	while(ptr) {
//		cout << ptr->val << endl;
//		ptr = ptr->next;
//	}
	ListNode * answer = sol.insertionSortList(head);
	while(answer) {
		cout << answer->val << endl;
		answer = answer->next;
	}
	return 0;
}
