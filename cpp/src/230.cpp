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
    int kthSmallest(TreeNode* root, int k) {
		int left_num = getnum(root->left);
		if(left_num == k-1) return root->val;
		else if(left_num > k - 1) {
			root = root->left;
			return kthSmallest(root,k);
		} else{
			root = root->right;
			return kthSmallest(root,k-left_num-1);
		}
		return 0;
    }
	
	int getnum(TreeNode *root) {
		int ret = 0;
		if(root != NULL) {
			ret += 1 + getnum(root->left) + getnum(root->right);
		}
		return ret;
	}
};


int main() {
	vector<int> vec = {3,1,4,2};
	TreeNode *node[(int)vec.size()];
	for(int i=0;i<(int)vec.size();++i){
		node[i] = new TreeNode(vec[i]);
	}
	node[0]->left = node[1];
	node[0]->right = node[2];
	node[1]->right = node[3];
	Solution sol;
	cout << sol.kthSmallest(node[0],1) << endl;
	return 0;
}
