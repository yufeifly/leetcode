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
	ListNode* mergeKLists(vector<ListNode*> &lists) {
		int sz = (int)lists.size();
		int interval = 1;
		while(interval < sz) {
			for(int i=0;i + interval <sz;i+=2*interval) {
				lists[i] = merge2Lists(lists[i],lists[i+interval]);
			}
			interval = interval * 2;
		}
		return lists[0];
	}

	ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		while(l1 != NULL && l2 != NULL) {
			if(l1->val <= l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l1;
				l1 = p->next->next;
			}
			p = p->next;
		}
		if(l1) {
			p->next = l1;
		}
		if(l2) {
			p->next = l2;
		}
		return head->next;
	}
};

ListNode* init(vector<int> &vec) {
	if((int)vec.size() <= 0) {
		return NULL;
	}
	ListNode *head = new ListNode(vec[0]);
	for(int i=1;i<(int)vec.size();++i) {
		ListNode *node = new ListNode(vec[i]);
		ListNode *p = head;
		while(p->next) p = p->next;
		p->next = node;
	}
	return head;
}

int main() {
	Solution sol;
	vector<vector<int>> vec = {
		{1,4,5},
		{1,3,4},
		{2,6}
	};
	vector<ListNode*> vl;
	for(int i=0;i<(int)vec.size();++i) {
		ListNode *list = init(vec[i]);
		vl.push_back(list);
	}
	//
//	for(auto l : vl) {
//		while(l) {
//			cout << l->val << " ";
//			l = l->next;
//		}
//		cout << endl;
//	}
	//
	ListNode *answer = sol.mergeKLists(vl);
	while(answer) {
		cout << answer->val << " ";
		answer = answer->next;
	}
	cout << endl;
	return 0;
}
