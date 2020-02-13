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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(0,(int)inorder.size()-1,0,(int)postorder.size()-1,
				inorder,postorder);
    }

	TreeNode* build(int left_in, int right_in,int left_post,int right_post,
			vector<int> &in, vector<int> &post) {
		if(left_in > right_in) {
			return NULL;
		}
		TreeNode *new_node = new TreeNode(post[right_post]);
		int root_in = left_in;
		for(;root_in <= right_in;++root_in) {
			if(in[root_in] == post[right_post]) {
				break;
			}
		}
		int left_num = root_in - left_in;
		new_node->left = build(left_in,root_in-1,left_post,left_post+left_num-1,
				in,post);
		new_node->right = build(root_in+1,right_in,left_post+left_num,right_post-1,
				in,post);
		return new_node;
	}
};

void travel(TreeNode *root) {
	if(root != NULL) {
		cout << root->val << " ";
		travel(root->left);
		travel(root->right);
	}
}

int main() {
	vector<int> in = {9,3,15,20,7};
	vector<int> post = {9,15,7,20,3};
	Solution sol;
	TreeNode *answer = sol.buildTree(in,post);
	travel(answer);
	cout << endl;
	return 0;
}
