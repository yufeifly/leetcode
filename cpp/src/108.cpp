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
private:
	TreeNode * sort(vector<int> &nums, int min, int max) {
		if(min > max) return NULL;
		int mid = (min + max) / 2;
		TreeNode *new_node = new TreeNode(nums[mid]);
		new_node->left = sort(nums,min,mid-1);
		new_node->right = sort(nums,mid+1,max);
		return new_node;
	}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode * root = sort(nums,0,(int)nums.size()-1);
		return root;
	}
};

void inorder_print(TreeNode *root) {
	if(root != NULL) {
		inorder_print(root->left);
		cout << root->val << " ";
		inorder_print(root->right);
	}
}

int main() {
	vector<int> vec = {-10,-3,0,5,9};
	Solution sol;
	TreeNode *answer = sol.sortedArrayToBST(vec);
	inorder_print(answer);
	cout << endl;
	return 0;
}
