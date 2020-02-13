#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	TreeNode *flat(TreeNode *root) {
		if(root->left == NULL && root->right == NULL) {
			return root;
		} else if(root->left != NULL && root->right == NULL) {
			root->right = root->left;
			root->left = NULL;
			return flat(root->right);
		} else if(root->left == NULL && root->right != NULL) {
			return flat(root->right);
		} else {
			TreeNode *left_tail = flat(root->left);
			TreeNode *right_tail = flat(root->right);
			TreeNode *tmp = root->right;
			root->right = root->left;
			root->left = NULL;
			left_tail->right = tmp;
			return right_tail;
		}
		return NULL;
	}

public:
    void flatten(TreeNode* root) {
		if(root == NULL) return ;
        flat(root);
    }
};

void print(TreeNode *root) {
	if(root != NULL) {
		cout << root->val << " ";
		if(root->left != NULL) {
			cout << "error" << endl;
			return ;
		}
		print(root->right);
	}
}

int main() {
	vector<int> vec = {1,2,5,3,4,6};
	TreeNode *node[6] = {NULL};
	for(int i=0;i<(int)vec.size();++i) {
		node[i] = new TreeNode(vec[i]);
	}
	node[0]->left = node[1];
	node[0]->right = node[2];
	node[1]->left = node[3];
	node[1]->right = node[4];
	node[2]->right = node[5];
	Solution sol;
	sol.flatten(node[0]);
	print(node[0]);
	cout << endl;
	return 0;
}
